#include "ANIMAL.h"
#include <string>
#include <iostream>

using namespace std;

AnimalCross::AnimalCross() {

	breed = "";
	home = "";
}

AnimalCross::AnimalCross(string someBreed, string someHome) {

	AnimalCross();

	breed = someBreed;
	home = someHome;
}

//functions to GET private attributes
string AnimalCross::getBreed() {

	return breed;
}

string AnimalCross::getHome() {

	return home;
}

//functions to SET private attributes
void AnimalCross::setBreed(string someBreed) {

	breed = someBreed;

}

void AnimalCross::setHome(string someHome) {

	home = someHome;
}

void AnimalCross::printAll() {

	cout << "" << endl;
	cout << "Home: " << getHome() << endl;
	cout << "Breed: " << getBreed() << endl;

}

void AnimalCross::animalEat() {

	cout << "Yummy!" << endl;

}

void AnimalCross::animalMovement() {
	cout << "Animal move." << endl;
}