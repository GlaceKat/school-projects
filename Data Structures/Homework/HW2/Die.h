//Katerina Betts, Christian Dinevski, Donald Hutchinson, Emily Thie
// Data Structures Homework 2

#ifndef DIE_H
#define DIE_H

using namespace std;

class Die {

public:

	//Constructors
	Die();
	Die(int rollSide);

	//Set attribute
	void setNumSides(int newS);

	//Get attribute
	int getNumSides();

	//Rolls the n sided die
	int rollDie();

private:
	int numSides; //number of sides of the die



};

#endif