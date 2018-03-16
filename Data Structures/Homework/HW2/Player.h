//Katerina Betts, Christian Dinevski, Donald Hutchinson, Emily Thie
// Data Structures Homework 2

#ifndef PLAYER_H
#define PLAYER_H
#include "Die.h"


class Player {

public:

	//Constructors
	Player();
	Player(double newBalance);

	//Set attributes
	void setBalance(double newBalance);

	//Get attributes
	double getBalance();
	Die getDie();

private:
	double balance;
	Die die;

};

#endif
