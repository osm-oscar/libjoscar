#ifndef LIB_J_OSCAR_OBJECT_STORE_H
#define LIB_J_OSCAR_OBJECT_STORE_H
#pragma once
#include <vector>
#include <stack>
#include <limits>
#include <stdexcept>

#include <sserialize/utility/exceptions.h>
#include <sserialize/mt/MultiReaderSingleWriterLock.h>

namespace libjoscar {

template<typename T>
class ObjectStore {
public:
	using value_type = T;
public:
	ObjectStore() {}
	~ObjectStore();
	///locks a readlock
	bool count(int32_t id) const;
	///locks a writelock
	int32_t insert(T* ptr);
	///locks a readlock
	T * get(int32_t id);
	///locks a writelock
	void destroy(int32_t id);
private:
	bool unlocked_count(int32_t id) const;
private:
// 	using Mutex = sserialize::MultiReaderSingleWriterLock;
// 	using ReadLock = sserialize::MultiReaderSingleWriterLock::ReadLock;
// 	using WriteLock = sserialize::MultiReaderSingleWriterLock::WriteLock;
	
	using Mutex = std::mutex;
	using ReadLock = std::unique_lock<Mutex>;
	using WriteLock = std::unique_lock<Mutex>;
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
ObjectStore<T>::count(int32_t id) const {
	ReadLock lck(m_lock);
	return unlocked_count(id);
}

template<typename T>
bool
ObjectStore<T>::unlocked_count(int32_t id) const {
	return (id >= 0) && (m_d.size() > (std::size_t) id) && m_d[id];
}

template<typename T>
int32_t
ObjectStore<T>::insert(T * ptr) {
	WriteLock lck(m_lock);
	if (m_fl.size()) {
		int32_t id = m_fl.top();
		m_fl.pop();
		m_d[id] = ptr;
		return id;
	}
	else {
		int32_t id = m_d.size();
		m_d.emplace_back(ptr);
		return id;
	}
}

template<typename T>
T *
ObjectStore<T>::get(int32_t id) {
	ReadLock lck(m_lock);
	if (!unlocked_count(id)) {
		lck.unlock();
		throw sserialize::InvalidReferenceException("ObjectStore::get(id) with id=" + std::to_string(id));
		return 0;
	}
	return m_d[id];
}

template<typename T>
void
ObjectStore<T>::destroy(int32_t id) {
	WriteLock lck(m_lock);
	if (unlocked_count(id)) {
		delete m_d[id];
		m_d[id] = 0;
		m_fl.emplace(id);
	}
}

}

#endif
