#include <iostream>
#include "TASK1.h"

template <class T>
OrderedList<T>::OrderedList() {

	numItems = 0;

	// Initialize values to null pointers
	for (int i = 0; i < SIZE; i++) {
		array[i] = nullptr;
	}
}

template <class T>
void OrderedList<T>::AddItem(T *newVal) {

	int i = 0;

	if (numItems >= SIZE) {
		throw OverflowException();
	}

	// Search from beginning to find open spot or place to insert
	while (array[i] != nullptr && *newVal > *array[i]) {
		operations++;
		i++;

	}

	// Shift items up to insert value
	for (int j = numItems; j > i; j--) {
		array[j] = array[j - 1];
		operations += 2; // Comparison and move
	}

	array[i] = newVal;

	numItems++;

}

template <class T>
T* OrderedList<T>::RemoveItem(T removeVal) {

	int i = 0;

	if (numItems <= 0) {
		throw UnderflowException();
	}

	// Search from beginning to remove value
	while (*array[i] != removeVal) {
		operations++;
		i++;

	}

	T* ret = array[i];

	// Shift items down
	for (int j = i; j < numItems; j++) {
		if (j == SIZE - 1) {
			array[j] = nullptr;
		}
		else {
			array[j] = array[j + 1];
		}
		operations += 2;
	}

	numItems--;

	return ret;
}

template <class T>
void OrderedList<T>::MakeEmpty() {

	for (int i = 0; i < numItems; i++) {

		delete array[i];
		array[i] = nullptr;

	}

}

template <class T>
bool OrderedList<T>::IsEmpty() {

	return numItems == 0;

}

template <class T>
bool OrderedList<T>::IsFull() {

	return SIZE == numItems;

}