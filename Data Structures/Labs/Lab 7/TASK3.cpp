#include <iostream>
#include "TASK1.h"

#include "TASK3.h"

using namespace std;

template <class T>
void CheckBlanks<T>::AddItem(T *item) {	
	// Add item to beginning if list is empty
	if (IsEmpty()) {
		array[0] = item;
		numItems++;
		return;
	}

	int lower = SIZE - 1; // The index of the first number that is smaller than the input
	int upper = 0; // The index of the first number that is larger than the input
	int lowFreeSpace = -1; // Will be set to the index of a free space below the input's index, if it exists
	int highFreeSpace = -1; // Will be set to the index ofa free space above the input's index, if it exists

	// Search from end until a number lower than the input is reached
	while (lower > 0 && (array[lower] == nullptr || *array[lower] > *item)) {
		if (array[lower] == nullptr) {
			highFreeSpace = lower; // This is a free space above the input
		}

		operations++;
		lower--;
	}

	// Search from beginning until a number higher than the input is reached
	while (upper < SIZE - 1 && (array[upper] == nullptr || *array[upper] < *item)) {
		if (array[upper] == nullptr) {
			lowFreeSpace = upper; // This is a free space below the input
		}

		operations++;
		upper++;
	}

	// Find the index to place the input, halfway between upper and lower numbers
	int index = (upper + lower) / 2;


	// If the space is free, assign the item and return
	if (array[index] == nullptr) {
		array[index] = item;
		numItems++;
		return;
	}

	// If there's a free space below the index and the item is >= than what is currently there, shift down
	if (lowFreeSpace != -1 && *array[index] <= *item) {
		for (int i = lowFreeSpace; i < index; i++) {
			operations += 2;
			array[i] = array[i + 1];
		}
	}
	else {   // Shift up if there's no space below
		if (*array[index] <= *item) {
			index++; // increase index by one if the item is greater than what is currently at the index (we don't want to shift that value up above the item)
		}
		for (int i = highFreeSpace; i > index; i--) {
			operations += 2;
			array[i] = array[i - 1];
		}
	}



	array[index] = item;
	numItems++;
}

template <class T>
T* CheckBlanks<T>::RemoveItem(T removeVal) {
	int i = 0;

	if (numItems <= 0) {
		throw UnderflowException();
	}

	// Search from beginning for value
	while (array[i] == nullptr || *array[i] != removeVal) {
		operations++;
		i++;

	}

	T* ret = array[i];

	array[i] = nullptr;

	numItems--;

	return ret;

}