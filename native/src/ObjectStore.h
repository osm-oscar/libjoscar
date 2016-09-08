#ifndef LIB_J_OSCAR_OBJECT_STORE_H
#define LIB_J_OSCAR_OBJECT_STORE_H
#pragma once
#include <vector>
#include <stack>
#include <limits>
#include <stdexcept>

namespace libjoscar {

template<typename T>
class ObjectStore {
public:
	using value_type = T;
public:
	ObjectStore() {}
	~ObjectStore();
	bool count(int32_t id) const;
	int32_t insert(T* ptr);
	T * get(int32_t id);
	void destroy(int32_t id);
private:
	std::vector<value_type*> m_d;
	std::stack<std::size_t> m_fl; //free list
};


template<typename T>
ObjectStore<T>::~ObjectStore() {
	for(value_type * t : m_d) {
		delete t;
	}
}

template<typename T>
bool
ObjectStore<T>::count(int32_t id) const {
	return id >= 0 && m_d.size() > (std::size_t) id && m_d[id];
}

template<typename T>
int32_t
ObjectStore<T>::insert(T * ptr) {
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
	T * t = m_d.at(id);
	if (!t) {
		throw std::runtime_error("Nullpointer exception");
	}
	return t;
}

template<typename T>
void
ObjectStore<T>::destroy(int32_t id) {
	if (count(id)) {
		delete get(id);
		m_d[id] = 0;
		m_fl.emplace(id);
	}
}

}

#endif
