//Stack class Definition modeling side pile
//Data Structures Spring 2018
//Homework 3

#ifndef STACK_H
#define STACK_H
#include "Node.h"

using namespace std;

//Side pile max size
const int STACK_MAX = 5;

/*
A player cannot peek at what is in their side pile. A player
can add a card to the top or remove a card from the top. This needs a way to tell the
player how many cards they have left but not the other player
*/

class Stack{
    
    public:        
        bool IsFull() { return size == STACK_MAX; }
        bool IsEmpty() { return size == 0; }
        
        int GetLength() { return size; }
        
        //add a card to top
        void Push(int );
        
        //remove card from top
        int Pop () ;
        
    
    private:
		int size = 0;
        
		Node* top;
};

#endif