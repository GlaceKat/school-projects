#include "STABLE.h"
#include "HORSE.h"
#include <iostream>
#include <string>
#include "EXCEPTIONS.h"

using namespace std;

Stable::Stable() {
	numHorses = 0;
	stalls[HORSE_LIMIT];

}
void Stable::addHorse(HorseInfo horse) { //this adds a horse to the stable
	if (numHorses == HORSE_LIMIT) {
		throw FullStable();
	}
	stalls[numHorses] = horse;
	numHorses++;
}
HorseInfo Stable::removeHorse() { //this removes a horse from the stable
	if (numHorses == 0) {
		throw EmptyStable();
	}
	numHorses--;
	return stalls[numHorses];
}
int Stable::getNumHorses() { //this gets the number of horses in the stable

	return numHorses;

}
void Stable::PrintAll() { //prints the attributes of the horses

	for (int i = 0; i < numHorses; i++) {

		cout << "The type of horse: " << stalls[i].getBreed() << endl;
		cout << "Horse color: " << stalls[i].getHorseColor() << endl;
		cout << "Horse home: " << stalls[i].getHome() << endl;
	}

}