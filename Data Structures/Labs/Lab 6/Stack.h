#ifndef STACK_H
#define STACK_H

// A stack template class
template<class T>
class Stack {

public:

	//Constructor
	Stack();
	Stack(int maxsize);
	~Stack();

	void Push(T *newVal);
	T* Pop();
	T* Top();
	int getLength();
	void emptyStack();
	bool IsEmpty();
	bool IsFull();

	friend void printStack(Stack<T> &stack);
	friend int checkWin(Stack<T> *towers[], int NUM_TOWERS);

private:
	int top = 0;
	T **data;
	int MAX_SIZE;
};

class OverflowException {};
class UnderflowException {};

#endif