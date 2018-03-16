#include <iostream>
#include "TASK2.h"

using namespace std;

template <class T>
void EndList<T>::AddItem(T *item) {

	if (numItems >= SIZE) {
		throw OverflowException();
	}

	int i = numItems;

	// Search from end to find place to inserts
	while (i > 0 && *item < *array[i - 1]) {
		operations++;
		i--;
	}

	// Shift items up
	for (int j = numItems; j > i; j--) {
		array[j] = array[j - 1];
		operations += 2;
	}

	array[i] = item;

	numItems++;
}
