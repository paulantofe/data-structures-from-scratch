#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>

template <typename T> class DynamicArray {
private:
	T* arr;
	int capacity;
	int size;

	void doubleCapacity() {
		T* temp = new T[2 * capacity];

		for (int i = 0; i < size; i++)
			temp[i] = arr[i];

		delete[] arr;
		capacity *= 2;
		arr = temp;
	}

public:
	DynamicArray() : capacity(1), size(0) { arr = new T[capacity]; }

	DynamicArray(const DynamicArray& other) {
		capacity = other.capacity;
		size = other.size;

		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}

	DynamicArray& operator=(const DynamicArray& other) {
		if (this == &other)
			return *this;

		delete[] arr;
		capacity = other.capacity;
		size = other.size;

		arr = new T[capacity];
		for (int i = 0; i < size; i++)
			arr[i] = other.arr[i];

		return *this;
	}

	~DynamicArray()  { delete[] arr; }

	void push_back(const T& value) {
		if (size == capacity)
			doubleCapacity();

		arr[size++] = value;
	}

	void push(const T& value, int index) {
		if (index < 0 || index > size)
			throw std::out_of_range("Index out of bounds for insertion.");

		if (size == capacity)
			doubleCapacity();

		for (int i = size; i > index; i--)
			arr[i] = arr[i - 1];

		arr[index] = value;
		size++;
	}

	void print() const {
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;
	}
};

#endif