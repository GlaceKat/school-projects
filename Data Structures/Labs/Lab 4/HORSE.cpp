#include <iostream>
#include <string>
#include "ANIMAL.h"
#include "HORSE.h"

using namespace std;

HorseInfo::HorseInfo() : AnimalCross() {

	horseColor = "";
	breed = "";
	home = "Land";

}

HorseInfo::HorseInfo(string someBreed, string someHome, string someColor) : AnimalCross(someBreed, someHome) {

	setHorseColor(someColor);
}

void HorseInfo::setHorseColor(string someColor) {

	horseColor = someColor;
}

string HorseInfo::getHorseColor() {
	return horseColor;

}

void HorseInfo::animalEat() {
	cout << "Yummy grass." << endl;
}

void HorseInfo::animalMovement() {
	cout << "Walk, Trot, Canter, Gallop." << endl;
}
