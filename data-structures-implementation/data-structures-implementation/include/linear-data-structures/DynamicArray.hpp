#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T> class DynamicArray {
private:
	T* m_arr;
	unsigned int m_capacity;
	unsigned int m_size;

	void doubleCapacity() {
		T* temp = new T[2 * m_capacity];

		for (unsigned int i = 0; i < m_size; i++)
			temp[i] = m_arr[i];

		delete[] m_arr;
		m_capacity *= 2;
		m_arr = temp;
	}

public:
	DynamicArray() : m_capacity(1), m_size(0) { m_arr = new T[m_capacity]; }

	DynamicArray(const unsigned int initial_size) : m_capacity(initial_size), m_size(initial_size) {
		m_arr = new T[initial_size];
	}

	DynamicArray(const DynamicArray& other) {
		m_capacity = other.m_capacity;
		m_size = other.m_size;

		m_arr = new T[m_capacity];
		for (unsigned int i = 0; i < m_size; i++)
			m_arr[i] = other.m_arr[i];
	}

	DynamicArray& operator=(const DynamicArray& other) {
		if (this == &other)
			return *this;

		delete[] m_arr;
		m_capacity = other.m_capacity;
		m_size = other.m_size;

		m_arr = new T[m_capacity];
		for (unsigned int i = 0; i < m_size; i++)
			m_arr[i] = other.m_arr[i];

		return *this;
	}

	T& operator[](const unsigned int index) {
		return m_arr[index];
	}

	const T& operator[](const unsigned int index) const {
		return m_arr[index];
	}

	~DynamicArray()  { delete[] m_arr; } 

	void push_back(const T& value) {
		if (m_size == m_capacity)
			doubleCapacity();

		m_arr[m_size++] = value;
	} 

	void pop_back() {
		if (m_size == 0)
			return;
		m_size--;
	} 

	void remove(const unsigned int index) {
		if (index >= m_size)
			throw std::out_of_range("Index is out of range.");

		for (unsigned int i = index; i < m_size - 1; i++)
			m_arr[i] = m_arr[i + 1];
		m_size--;
	} 

	void push(const T& value, const unsigned int index) {
		if (index > m_size)
			throw std::out_of_range("Index out of bounds for insertion.");

		if (m_size == m_capacity)
			doubleCapacity();

		for (unsigned int i = m_size; i > index; i--)
			m_arr[i] = m_arr[i - 1];

		m_arr[index] = value;
		m_size++;
	} 

	void print() const {
		for (unsigned int i = 0; i < m_size; i++)
			std::cout << m_arr[i] << ' ';
		std::cout << std::endl;
	} 

	void clear() {
		m_size = 0;
	} 

	unsigned int size() const {
		return m_size;
	}

	unsigned int capacity() const {
		return m_capacity;
	}

	bool empty() const {
		return m_size == 0;
	}

	void resize(const unsigned int newSize) {
		T* temp = new T[newSize]();

		for (unsigned int i = 0; i < std::min(m_size, newSize); i++)
			temp[i] = m_arr[i];

		delete[] m_arr;

		m_arr = temp;
		m_size = newSize;
		m_capacity = newSize;
	}
};
