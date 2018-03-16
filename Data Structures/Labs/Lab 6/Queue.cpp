#include "Queue.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
Queue<T>::Queue() {
	front = 0;
	back = 0;
}

template <class T>
void Queue<T>::Enqueue(T item) {
	data.push_back(item);
	back++;
}

template <class T>
T Queue<T>::Dequeue() {
	if (IsEmpty()) throw QueueUnderflowException();

	T retVal = data[front];
	
	front++;

	return retVal;
}

template <class T>
T Queue<T>::Peek() {
	if (IsEmpty()) throw UnderflowException();

	return data[front];
}

template <class T>
int Queue<T>::Length() {
	return back - front;
}

template <class T>
bool Queue<T>::IsEmpty() {

	return back == front;

}