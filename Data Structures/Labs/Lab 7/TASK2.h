#ifndef TASK2
#define TASK2
#include "TASK1.h"

template <class T>
class EndList : public OrderedList<T> {

public:

	//Function that needs to be overridden
	void AddItem(T *item);
};


#endif