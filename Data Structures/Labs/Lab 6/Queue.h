#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

using namespace std;

template <class T>
class Queue {

public:
	//Functions Necessary in Queues
	Queue();

	void Enqueue(T item);
	T Dequeue();
	T Peek();
	int Length();
	bool IsEmpty();

private:

	int front, back;
	vector<T> data;
};

class QueueUnderflowException {};

#endif