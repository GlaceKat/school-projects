#include "Stack.h"
#include "Stack.cpp"
#include <iostream>


using namespace std;

// Print out a single stack as a stack of dashes
void printStack(Stack<int> &stack) {
	for (int i = stack.top - 1; i >= 0; i--) {
		for (int j = 0; j < *stack.data[i]; j++) {
			cout << "--";
		}
		cout << endl;
	}
}

int main() {
	int prompt = 0;
	int s = 0;
	int d = 0;
	int numDisks;
	const int NUM_TOWERS = 3;
	cout << "How many disks do you want to play with? ";
	cin >> numDisks;
	while (numDisks < 0) {
		cout << "The number you entered is invalid. Please reenter." << endl;
		cin >> numDisks;
		cout << endl;
	}

	cout << "The rules: \n"
		"Only one disk can be moved at a time.\n"
		"Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.\n"
		"No disk may be placed on top of a smaller disk." << endl << endl;

	// Create towers
	Stack<int> *towers[NUM_TOWERS];
	for (int i = 0; i < NUM_TOWERS; i++) {
		towers[i] = new Stack<int>(numDisks);
	}

	// Fill towers with disks, represented by integers that correspond to their size
	for (int i = numDisks; i > 0; i--) {
		int *val = new int;
		*val = i;
		towers[0]->Push(val);
	}

	// Loop until the player wins
	while (!towers[2]->IsFull()) {
		cout << endl;
		// Display the towers
		for (int i = 0; i < NUM_TOWERS; i++)
		{
			cout << "Tower " << i << ":\n";
			printStack(*towers[i]);
			cout << endl;
		}

		// Ask user for move
		cout << endl;
		cout << "Enter source stack (0 through # of stacks)" << endl;
		cin >> s;
		cout << "Enter destination stack (0 through # of stacks)" << endl;
		cin >> d;

		while (s < 0 || s >= NUM_TOWERS || d < 0 || d >= NUM_TOWERS) {
			cout << "Invalid source/destination.\n";
			cout << "Enter source stack (0 through # of stacks)" << endl;
			cin >> s;
			cout << "Enter destination stack (0 through # of stacks)" << endl;
			cin >> d;
		}

		try {
			int *disk = towers[s]->Top();

			if (towers[d]->IsEmpty() || *disk < *(towers[d]->Top())) {
				towers[d]->Push(disk);
				towers[s]->Pop(); // Remove the disk from the source tower if the move was succesful
			}
			else {
				cout << "Invalid move.\n";
			}
		}
		catch (OverflowException) {
			cout << "Invalid move.\n";
		}
		catch (UnderflowException) {
			cout << "Invalid move.\n";
		}
	}

	for (int i = 0; i < NUM_TOWERS; i++)
	{
		cout << "Tower " << i << ":\n";
		printStack(*towers[i]);
		cout << endl;
	}

	cout << "You win!" << endl;

	for (int i = 0; i < NUM_TOWERS; i++) {
		delete towers[i];
	}

	return 0;
}
