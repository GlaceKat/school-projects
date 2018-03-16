#include "Stack.h"
#include "Stack.cpp"
#include "Disk.h"
#include <iostream>


using namespace std;

// Print out a stack as a stack of dashes
void printStack(Stack<Disk> &stack) {
	for (int i = stack.top - 1; i >= 0; i--) {
		for (int j = 0; j < stack.data[i]->size; j++) {
			if (stack.data[i]->player == 1) {
				cout << "--";
			}
			else {
				cout << "~~";
			}
		}
		cout << endl;
	}
}

// Check if a player has a full stack on the opposite side
int checkWin(Stack<Disk> *towers[], int NUM_TOWERS) {
	int lower = floor(double(NUM_TOWERS) / 2);
	int upper = floor(double(NUM_TOWERS + 1) / 2);

	// Check left towers for player 2 win
	for (int i = 0; i < lower; i++) {
		Stack<Disk> *tower = towers[i];
		bool win = true;

		if (tower->IsFull()) {
			for (int j = 0; j < tower->top; j++) {
				if (tower->data[j]->player == 1) {
					win = false; // If the other player has a disk in the tower, it is not a win
				}
			}

			if (win) {
				return 2;
			}
		}
	}

	// Check right towers for player 1 win
	for (int i = upper; i < NUM_TOWERS; i++) {
		Stack<Disk> *tower = towers[i];
		bool win = true;

		if (tower->IsFull()) {
			for (int j = 0; j < tower->top; j++) {
				if (tower->data[j]->player == 2) {
					win = false;
				}
			}

			if (win) {
				return 1;
			}
		}
	}

	// No winner yet
	return 0;
}

int main() {
	int prompt = 0;
	int s = 0;
	int d = 0;
	int numDisks;
	const int NUM_TOWERS = 5;
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
	Stack<Disk> *towers[NUM_TOWERS];
	for (int i = 0; i < NUM_TOWERS; i++) {
		towers[i] = new Stack<Disk>(numDisks);
	}

	// Fill towers with disks, represented by integers that correspond to their size
	for (int i = numDisks; i > 0; i--) {
		Disk *disk = new Disk;
		disk->size = i;
		disk->player = 1;
		towers[0]->Push(disk);
	}
	for (int i = numDisks; i > 0; i--) {
		Disk *disk = new Disk;
		disk->size = i;
		disk->player = 2;
		towers[NUM_TOWERS-1]->Push(disk);
	}
	
	int winner = 0;
	while (winner == 0) { // Loop until there is a winner
		cout << endl;
		for (int i = 0; i < NUM_TOWERS; i++)
		{
			cout << "Tower " << i << ":\n";
			printStack(*towers[i]);
			cout << endl;
		}
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
			Disk *disk = towers[s]->Top();

			if (towers[d]->IsEmpty() || disk->size <= towers[d]->Top()->size) {
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

		// Check for a winner after a move is made
		winner = checkWin(towers, NUM_TOWERS);
	}

	for (int i = 0; i < NUM_TOWERS; i++)
	{
		cout << "Tower " << i << ":\n";
		printStack(*towers[i]);
		cout << endl;
	}

	cout << "Player " << winner << " wins!" << endl;

	for (int i = 0; i < NUM_TOWERS; i++) {
		delete towers[i]; // Delete each tower
	}

	return 0;
}
