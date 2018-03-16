//Katerina Betts, Christian Dinevski, Donald Hutchinson, Emily Thie
// Data Structures Homework 2

#include <iostream>
#include <ctime>
#include "Die.h"

using namespace std;

Die::Die() {
	srand(time(NULL));
	setNumSides(6);

}

Die::Die(int newSide) {
	srand(time(NULL));
	setNumSides(6); //this is just in case the user inputs an invalid number.
	setNumSides(newSide);

}

void Die::setNumSides(int newSide) { //sets how many sides the die has


	if (newSide <= 20 && newSide >= 6) {
		numSides = newSide;
	}
	else {
		cout << "This is not a valid number of sides." << endl;
	}

}

int Die::getNumSides() {

	return numSides;

}

int Die::rollDie() { //randomly "rolls" the die



	return rand() % getNumSides() + 1;

}
