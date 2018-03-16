#include "ANIMALCOLLECTION.h"
#include <iostream>
#include <string>
#include "EXCEPTIONS.h"

using namespace std;

template <class T>
AnimalCollection<T>::AnimalCollection() {
	numAnimals = 0;
	stalls[ANIMAL_LIMIT];

}

template <class T>
void AnimalCollection<T>::addAnimal(T animal) { //this adds a horse to the stable
	if (numAnimals == ANIMAL_LIMIT) {
		throw FullStable();
	}
	stalls[numAnimals] = animal;
	numAnimals++;
}

template <class T>
T AnimalCollection<T>::removeAnimal() { //this removes a horse from the stable
	if (numAnimals == 0) {
		throw EmptyStable();
	}
	numAnimals--;
	return stalls[numAnimals];
}

template <class T>
int AnimalCollection<T>::getNumAnimals() { //this gets the number of horses in the stable

	return numAnimals;

}

template <class T>
void AnimalCollection<T>::PrintAll() { //prints the attributes of the horses

	for (int i = 0; i < numAnimals; i++) {

		cout << "The breed of animal: " << stalls[i].getBreed() << endl;
		cout << "Animal home: " << stalls[i].getHome() << endl;
	}

}