#include "Stack.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack() {
	Stack(3);
}
template <class T>
Stack<T>::Stack(int maxsize) {
	MAX_SIZE = maxsize;
	data = new T*[MAX_SIZE]; // Allocate memory for array

	for (int i = 0; i < MAX_SIZE; i++) {
		data[i] = nullptr;
	}
}
template <class T>
void Stack<T>::Push(T* newVal) {
	if (IsFull()) throw OverflowException();

	data[top] = newVal;
	top++;
}
template <class T>
T* Stack<T>::Pop() {
	if (IsEmpty()) throw UnderflowException();

	T* temp;
	top--;
	temp = data[top];
	return temp;
}
template <class T>
T* Stack<T>::Top() {
	if (IsEmpty()) throw UnderflowException();

	T* temp;
	temp = data[top - 1];
	return temp;
}
template <class T>
bool Stack<T>::IsEmpty() {
	return top <= 0;
}
template <class T>
bool Stack<T>::IsFull() {
	return top >= MAX_SIZE;
}
template <class T>
int Stack<T>::getLength() {
	return top;
}
template <class T>
void Stack<T>::emptyStack() {
	for (int i = 0; i < top; i++) { // Delete each stored pointer
		if (data[i] != nullptr) {
			delete data[i];
		}
	}

	top = 0;
}
template <class T>
Stack<T>::~Stack() {
	emptyStack(); // Empty the stack and delete the dynamically allocated array
	delete[] data;
}