//Deck class Definition: like a queue
//Data Structures Spring 2018
//Homework 3

#include <iostream>
#include "Queue.h"
#include "Exceptions.h"

using namespace std;

//provide card from beginning of queue
int Queue::Dequeue() {
    if (IsEmpty()) {
		throw EmptyException();
    }

	int retVal = front->data;
	Node *oldFront = front;
	front = front->next;
	delete oldFront; // avoid memory leak
	length--;
	return retVal;
}

// add card to end of queue
void Queue::Enqueue(int in) {
	if (IsFull()) {
		throw FullException();
	}

	Node *n = new Node; // Create a node to hold card, delete later when removed
	n->data = in;
	n->prev = end;
	n->next = NULL;
	if(end != NULL) end->next = n;
	end = n;
	length++;

	if (front == NULL) front = n;
}