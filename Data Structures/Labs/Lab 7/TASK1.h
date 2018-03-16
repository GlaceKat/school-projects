#ifndef TASK1
#define TASK1

template <class T>
class OrderedList {

public:
	//Constructors
	OrderedList();

	//Functions to maintain the list
	void AddItem(T *newVal);
	T* RemoveItem(T newVal);
	void MakeEmpty();
	bool IsEmpty(); //checks if the list is empty
	bool IsFull(); //checks if the list is full of items

	int operations = 0; // Count the number of operations performed

protected:
	//Contains the number of items in the array
	int numItems;

	static const int SIZE = 20;

	//Array of pointers with limit of variable SIZE
	T *array[SIZE];

	//Exceptions required to be thrown
	class OverflowException {};
	class UnderflowException {};
};





#endif