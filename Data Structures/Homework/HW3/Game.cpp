#include "Queue.h"
#include "Stack.h"
#include "Exceptions.h"
#include <iostream>
#include <time.h>

using namespace std;

int main() {
	Stack playerPile;
	Stack computerPile;
	Queue playerDeck;
	Queue computerDeck;
	int numRounds = 0;
	int maxRounds;
	int type;
	int playerWins = 0;
	int computerWins = 0;
	bool winner = false;

	cout << "Style of play?" << endl;
	cout << "1. Until out of cards" << endl;
	cout << "2. Number of rounds" << endl;
	cin >> type;

	if (type == 1) { // End if one player is out of cards
		winner = !(playerPile.IsEmpty() && playerDeck.IsEmpty()) && !(computerPile.IsEmpty() && computerDeck.IsEmpty());
	}
	if (type == 2) { // End after number of rounds
		cout << "Enter number of rounds to play: ";
		cin >> maxRounds;
		winner = (numRounds == maxRounds);
	}
	
	srand(time(NULL));

	// Cards available to fill the decks with at the start of the game (13 suits)
	int cards[13];

	// 4 of each suit
	for (int i = 0; i < 13; i++)
	{
		cards[i] = 4;
	}

	// Fill the player and computer decks with the cards
	for (int i = 0; i < 26; i++)
	{
		// Choose a card and add it to the player's deck
		int c = rand() % 13;
		while (cards[c] <= 0)
		{
			c = rand() % 13;
		}
		playerDeck.Enqueue(c + 2);
		cards[c]--;

		// Choose a card and add it to the computer's deck
		c = rand() % 13;
		while (cards[c] <= 0)
		{
			c = rand() % 13;
		}
		computerDeck.Enqueue(c + 2);
		cards[c]--;
	}

	// Play until there is a winner
	while (!winner) {
		int computerCard = computerDeck.Dequeue();
		int playerCard = playerDeck.Dequeue();
		int newPlayerCard = 0;
		int newComputerCard = 0;
		int choice = 0;
		int playerTotal;
		int computerTotal = computerCard;
		bool error = true;

		// If there is in invalid input or the user just wants to check cards, don't continue with the game
		while (error || choice < 1 || choice > 3) {
			error = false;
			cout << "Your card is: " << playerCard << endl;
			cout << "1. Play the card" << endl;
			cout << "2. Draw a card from side pile and play both" << endl;
			cout << "3. Push the card onto the side pile and draw a new card" << endl;
			cout << "4. Check number of cards in deck" << endl;
			cout << "5. Check number of cards in pile" << endl;
			cin >> choice;

			cout << endl;

			if (choice == 2 && playerPile.IsEmpty()) {
				cout << "Your side pile is empty!" << endl << endl;
				error = true;
			}
			else if (choice == 3 && playerPile.IsFull()) {
				cout << "Your side pile is full!" << endl << endl;
				error = true;
			}
			else if (choice == 3 && playerDeck.IsEmpty()) {
				cout << "Your deck is empty, you must play this card." << endl << endl;
				error = true;
			}
			else if (choice == 4) {
				cout << "There are " << playerDeck.GetLength() << " cards in your deck." << endl;
			}
			else if (choice == 5) {
				cout << "There are " << playerPile.GetLength() << " cards in your side pile." << endl;
			}
			else if (choice < 1 || choice > 5) {
				cout << "Invalid input." << endl;
			}
		}

		// If the computer's card could use a boost, draw from side pile
		if (computerCard < 10 && !computerPile.IsEmpty()) {
			newComputerCard = computerPile.Pop();
		}

		// If computer's card is very low, push onto side pile
		if (computerCard < 6 && !computerPile.IsFull() && !computerDeck.IsEmpty()) {
			computerPile.Push(computerCard);
			computerCard = computerDeck.Dequeue();
		}


		switch (choice) {
		case 2:
			newPlayerCard = playerPile.Pop(); // Draw a new card from the pile to add to the total
			cout << "You drew a : " << newPlayerCard << endl; 
			break;
		case 3:
			playerPile.Push(playerCard); // Push the card onto the pile and draw a new card
			playerCard = playerDeck.Dequeue();
			break;
		default:
			break;
		}

		cout << endl;

		// Compute totals, new cards are 0 if they were not drawn from side
		playerTotal = playerCard + newPlayerCard;
		computerTotal = computerCard + newComputerCard;

		cout << "Your total: " << playerTotal << endl;
		cout << "Computer total: " << computerTotal << endl;

		// Determine winner
		if (playerTotal > computerTotal) {
			cout << "You win the hand!" << endl;
			playerDeck.Enqueue(computerCard);
			playerDeck.Enqueue(playerCard); // Give both cards to player
			playerWins++;
		}
		else {
			cout << "You lose the hand..." << endl;
			computerDeck.Enqueue(playerCard);
			if (choice == 2) {
				computerDeck.Enqueue(newPlayerCard); // If the player drew a new card, give to computer
			}
			computerDeck.Enqueue(computerCard); // Give both cards to computer
			computerWins++;
		}

		cout << endl;

		numRounds++;

		if (type == 1) { // End if one player is out of cards
			winner = (playerPile.IsEmpty() && playerDeck.IsEmpty()) || (computerPile.IsEmpty() && computerDeck.IsEmpty());
		}
		if (type == 2) {
			winner = (numRounds == maxRounds);
		}
	}

	cout << endl;

	if (type == 1) {
		if (playerPile.IsEmpty() && playerDeck.IsEmpty()) {
			cout << "You lose..." << endl;
		}
		else {
			cout << "You win!" << endl;
		}
	}
	else {
		if (playerWins > computerWins) {
			cout << "You win!" << endl;
		}
		else if (computerWins > playerWins) {
			cout << "You lose..." << endl;
		}
		else
		{
			cout << "It's a tie." << endl;
		}
	}

	// Empty decks to avoid memory leaks
	while (!playerDeck.IsEmpty()) {
		playerDeck.Dequeue();
	}
	while (!playerPile.IsEmpty()) {
		playerPile.Pop();
	}
	while (!computerDeck.IsEmpty()) {
		computerDeck.Dequeue();
	}
	while (!computerPile.IsEmpty()) {
		computerPile.Pop();
	}
}