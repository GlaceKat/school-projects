#ifndef TASK3
#define TASK3

#include "TASK1.h"

template <class T>
class CheckBlanks : public OrderedList<T> {

public:
	//Functions that needs overridden
	void AddItem(T *item);
	T* RemoveItem(T item);
};

#endif