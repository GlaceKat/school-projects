//Stack class Declaration: modeling side pile
//Data Structures Spring 2018
//Homework 3

#include <iostream>
#include "Stack.h"
#include "Exceptions.h"

using namespace std;

//add a card to top
void Stack::Push(int val) {
	if (IsFull()) {
		throw FullException();
	}
    
	Node* n = new Node; // Create a node to hold card, delete later when removed
	n->data = val;
	n->next = top;
	top = n;
	size++;
}

//remove card from top
int Stack::Pop () {
	if (IsEmpty()) {
		throw EmptyException();
	}
    
	int retVal = top->data;
	Node* oldTop = top;
	top = top->next;
	delete oldTop; // avoid memory leak
	size--;
	return retVal;
}