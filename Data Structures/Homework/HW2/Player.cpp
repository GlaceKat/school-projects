//Katerina Betts, Christian Dinevski, Donald Hutchinson, Emily Thie
// Data Structures Homework 2

#include <iostream>
#include "Player.h"
#include "Die.h"

using namespace std;

Player::Player() {

	balance = 100;
}

Player::Player(double newBalance) {

	balance = newBalance;

}

void Player::setBalance(double newBalance) {

	balance = newBalance;

}
double Player::getBalance() {

	return balance;
}

Die Player::getDie() {

	return die;

}
