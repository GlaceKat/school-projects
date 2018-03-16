#ifndef ANIMALCOLLECTION_H
#define ANIMALCOLLECTION_H

const int ANIMAL_LIMIT = 10;

template <class T>
class AnimalCollection {

public:
	AnimalCollection();

	void addAnimal(T animal);
	T removeAnimal();

	int getNumAnimals();

	void PrintAll();

private:

	T stalls[ANIMAL_LIMIT];
	int numAnimals = 0;

};

#endif