#ifndef LIB_J_OSCAR_OBJECT_STORE_H
#define LIB_J_OSCAR_OBJECT_STORE_H
#pragma once
#include <vector>
#include <stack>
#include <limits>
#include <stdexcept>
#include <atomic>
#include <functional>

#include <sserialize/utility/exceptions.h>
#include <sserialize/mt/MultiReaderSingleWriterLock.h>
#include "types.h"

namespace libjoscar {
namespace detail {

template<typename T>
class ObjectStore {
public:
	using value_type = T;
public:
	ObjectStore() {}
	~ObjectStore();
	///locks a readlock
	bool count(JavaNativeHandle id) const;
	///locks a writelock
	JavaNativeHandle insert(T* ptr);
	///locks a readlock
	T * get(JavaNativeHandle id);
	///locks a writelock
	void destroy(JavaNativeHandle id);
private:
	bool unlocked_count(JavaNativeHandle id) const;
private:
// 	using Mutex = sserialize::MultiReaderSingleWriterLock;
// 	using ReadLock = sserialize::MultiReaderSingleWriterLock::ReadLock;
// 	using WriteLock = sserialize::MultiReaderSingleWriterLock::WriteLock;
	
	using Mutex = std::mutex;
	using ReadLock = std::unique_lock<Mutex>;
	using WriteLock = ReadLock;
private:
	mutable Mutex m_lock;
	std::vector<value_type*> m_d;
	std::stack<std::size_t> m_fl; //free list
};

template<typename T>
ObjectStore<T>::~ObjectStore() {
	WriteLock lck(m_lock);
	for(value_type * t : m_d) {
		delete t;
	}
	m_d.clear();
	m_fl = decltype(m_fl)();
}

template<typename T>
bool
ObjectStore<T>::count(JavaNativeHandle id) const {
	ReadLock lck(m_lock);
	return unlocked_count(id);
}

template<typename T>
bool
ObjectStore<T>::unlocked_count(JavaNativeHandle id) const {
	return ( (int64_t)m_d.size() > (int64_t) id) && m_d[id];
}

template<typename T>
JavaNativeHandle
ObjectStore<T>::insert(T* ptr) {
	WriteLock lck(m_lock);
	if (m_fl.size()) {
		JavaNativeHandle id = m_fl.top();
		m_fl.pop();
		m_d[id] = ptr;
		return id;
	}
	else {
		JavaNativeHandle id = m_d.size();
		m_d.emplace_back(ptr);
		return id;
	}
}

template<typename T>
T *
ObjectStore<T>::get(JavaNativeHandle id) {
	ReadLock lck(m_lock);
	if (unlocked_count(id)) {
		return m_d[id];
	}
	else {
		lck.unlock();
		throw sserialize::InvalidReferenceException("ObjectStore::get(id) with id=" + std::to_string(id));
		return 0;
	}
}

template<typename T>
void
ObjectStore<T>::destroy(JavaNativeHandle id) {
	WriteLock lck(m_lock);
	if (unlocked_count(id)) {
		delete m_d[id];
		m_d[id] = 0;
		m_fl.emplace(id);
	}
}

template<typename T, std::size_t T_SHIFT>
class SlotedObjectStore {
public:
	using value_type = T;
public:
	SlotedObjectStore() : m_last(0) {}
	~SlotedObjectStore() {}
	///locks a readlock
	bool count(JavaNativeHandle id) const {
		std::size_t mySlot = this->slot(id);
		JavaNativeHandle mySlotId = this->slotId(id);
		return m_d.at(mySlot).count(mySlotId);
	}
	///locks a writelock
	JavaNativeHandle insert(T* ptr) {
		std::size_t mySlot = m_last.fetch_add(1, std::memory_order_relaxed) % num_slots();
		JavaNativeHandle id = m_d[mySlot].insert(ptr);
		return slotId2Id(id, mySlot);
	}
	///locks a readlock
	T * get(JavaNativeHandle id) {
		std::size_t mySlot = this->slot(id);
		JavaNativeHandle mySlotId = this->slotId(id);
		return m_d.at(mySlot).get(mySlotId);
	}
	///locks a writelock
	void destroy(JavaNativeHandle id) {
		std::size_t mySlot = this->slot(id);
		JavaNativeHandle mySlotId = this->slotId(id);
		return m_d.at(mySlot).destroy(mySlotId);
	}
private:
	inline constexpr std::size_t num_slots() const {
		return (1 << T_SHIFT);
	}
	inline std::size_t slot(JavaNativeHandle id) const {
		return id - ((id >> T_SHIFT) << T_SHIFT);
	}
	inline JavaNativeHandle slotId(JavaNativeHandle id) const {
		return id >> T_SHIFT;
	}
	inline JavaNativeHandle slotId2Id(JavaNativeHandle id, std::size_t slot) const {
		return (id << T_SHIFT) | slot;
	}
private:
	std::array<ObjectStore<value_type>, (1 << T_SHIFT)> m_d;
	std::atomic<std::size_t> m_last;
};

template<typename T>
class CastObjectStore {
public:
	using value_type = typename std::enable_if<sizeof(T*) <= sizeof(JavaNativeHandle), T>::type;
public:
	CastObjectStore() {}
	~CastObjectStore() {}
	bool count(JavaNativeHandle id) const { return id != 0; }
	JavaNativeHandle insert(value_type* ptr) { return reinterpret_cast<JavaNativeHandle>(ptr); }
	value_type * get(JavaNativeHandle id) { return reinterpret_cast<value_type*>(id); }
	void destroy(JavaNativeHandle id) { delete get(id); }
};

}//end namespace detail

template<typename T>
// using ObjectStore = detail::SlotedObjectStore<T, 6>;
using ObjectStore = detail::CastObjectStore<T>;

}

#endif
