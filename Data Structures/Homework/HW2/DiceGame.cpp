//Katerina Betts, Christian Dinevski, Donald Hutchinson, Emily Thie
//Data Structures Homework 2


#include <iostream>
#include <ctime>
#include "Player.h"
#include "Die.h"

using namespace std;

double amountWon(Die playerDie, Die houseDie, double wager) { //This returns the amount won in order to increase or decrease the player's balance

	double wagerIncrease = 0;
	int playerRoll = playerDie.rollDie();
	int houseRoll = houseDie.rollDie();


	cout << "Your roll is " << playerRoll << ". \n";
	cout << "How much would you like to increase the wager? \n";
	cin >> wagerIncrease;

	while (wagerIncrease < 0 || wagerIncrease >(wager * 2)) { //if an invalid roll

		cout << "This is NOT valid number to input.  Please input a different number. \n";
		cin >> wagerIncrease;

	}

	wager = wager + wagerIncrease; //increasing the wager by 0 to double the original wager within reason

	cout << "The house rolled " << houseRoll << endl;

	if (houseRoll >= playerRoll) {

		return -wager;

	}
	else {

		return wager;

	}

}

int main() {
	Player firstPlayer; //various variables needed throughout the main for testing
	Die house;
	char prompt = 'y';
	int wager = 0;
	int houseWinCount = 0;
	char hardPrompt;

	cout << "Hard mode (y/n)? \n"; //bonus was implemented
	cin >> hardPrompt;
	hardPrompt = tolower(hardPrompt);

	while (prompt == 'y') {
		cout << "Your balance is $" << firstPlayer.getBalance() << "." << endl;
		cout << "How much would you like to wager?" << endl;
		cin >> wager;

		double winnings = amountWon(firstPlayer.getDie(), house, wager);

		firstPlayer.setBalance(firstPlayer.getBalance() + winnings);

		if (hardPrompt == 'y') { //where hard prompt begins if it was chosen
			if (winnings > 0 && house.getNumSides() < 20) {
				house.setNumSides(house.getNumSides() + 1);
			}
			else {
				houseWinCount++;

				if (houseWinCount == 2 && house.getNumSides() > 6) {
					house.setNumSides(house.getNumSides() - 1);
					houseWinCount = 0;
				}
			}
		}

		if (firstPlayer.getBalance() <= 0) { //if the player runs out of money

			cout << "Game Over.  Would you like to play again (y/n)? \n";
			cin >> prompt;
			firstPlayer.setBalance(100);
		}
		else { //if the player still has money left over, but they want to continue
			cout << "Your balance is $" << firstPlayer.getBalance() << "." << endl;
			cout << "Would you like to play another round (y/n)? \n";
			cin >> prompt;
		}
	}

	return 0;
}