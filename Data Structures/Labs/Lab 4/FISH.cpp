#include <iostream>
#include <string>
#include "ANIMAL.h"
#include "FISH.h"

using namespace std;


FishInfo::FishInfo() : AnimalCross() {

	fishType = "";
	breed = "";
	home = "Water";

}

FishInfo::FishInfo(string someBreed, string someHome, string someType) : AnimalCross(someBreed, someHome) {

	setType(someType);
}

void FishInfo::setType(string type) {

	fishType = type;

}

string FishInfo::getType() {

	return fishType;

}

void FishInfo::animalMovement() {
	cout << "Just keep swimming." << endl;
}

void FishInfo::animalEat() {
	cout << "Yummy Fish Food." << endl;
}