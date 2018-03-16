//Deck class Definition that is like a queue
//Data Structures Spring 2018
//Homework 3

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

using namespace std;

//Will model a deck of cards
const int QUEUE_MAX = 52;

/*
This will provide a card from the top and return
all cards won to the bottom. This needs to be able to tell the player how many cards they
have left. The player can ask how many cards the computer has left in their deck.
*/

class Queue{
    
    public:        
        bool IsEmpty() { return length==0; }
        
        bool IsFull() { return length==QUEUE_MAX; }
        
        
        int GetLength() { return length; }
        
        //provide card from top
        int Dequeue() ;
        
        //returns cars won to bottom of stack
        void Enqueue(int);
    
    private:
        //For beginning and end of queue
		Node *front;
		Node *end;
        
        //To track length of queue
        int length = 0;
};

#endif