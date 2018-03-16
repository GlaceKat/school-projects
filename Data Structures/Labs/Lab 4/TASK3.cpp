#include "ANIMAL.h"
#include "FISH.h"
#include "HORSE.h"
#include <iostream>

using namespace std;

void callFunctions(AnimalCross* animal) {
	cout << "Inside function: " << endl;
	animal->animalEat();
	animal->animalMovement();
}

int main() {

	int in = 0;
	while (in != 6) {
		cout << "Press 1 for an instance of animal.\n";
		cout << "Press 2 for an instance of fish.\n";
		cout << "Press 3 for an instance of horse.\n";
		cout << "Press 4 for an instance of a fish declared as an animal.\n";
		cout << "Press 5 for an instance of a horse declared as an animal.\n";
		cout << "Press 6 to quit.\n";
		cin >> in;

		cout << endl;

		string breed, home;

		if (in < 6 && in > 0) {
			cout << "Enter the breed: ";
			cin >> breed;
			cout << "Enter the home: ";
			cin >> home;
		}

		switch (in) {
		case 1: {
			cout << endl;
			AnimalCross animal(breed, home);
			cout << "Outside function:" << endl;
			animal.animalEat();
			animal.animalMovement();
			callFunctions(&animal);
			break;
		}
		case 2: {
			string type;
			cout << "Enter the type: ";
			cin >> type;
			cout << endl;
			FishInfo fish(breed, home, type);
			cout << "Outside function:" << endl;
			fish.animalEat();
			fish.animalMovement();
			callFunctions(&fish);
			break;
		}
		case 3: {
			string color;
			cout << "Enter the color: ";
			cin >> color;
			cout << endl;
			HorseInfo horse(breed, home, color);
			cout << "Outside function:" << endl;
			horse.animalEat();
			horse.animalMovement();
			callFunctions(&horse);
			break;
		}
		case 4: {
			string type;
			cout << "Enter the type: ";
			cin >> type;
			cout << endl;
			AnimalCross* fish = new FishInfo(breed, home, type);
			cout << "Outside function:" << endl;
			fish->animalEat();
			fish->animalMovement();
			callFunctions(fish);
			delete fish;
			break;
		}
		case 5: {
			string color;
			cout << "Enter the color: ";
			cin >> color;
			cout << endl;
			AnimalCross* horse = new HorseInfo(breed, home, color);
			cout << "Outside function:" << endl;
			horse->animalEat();
			horse->animalMovement();
			callFunctions(horse);
			delete horse;
			break;
		}
		case 6: {
			break;
		}
		default: {
			cout << "That is not a valid input.\n";
		}
		}

		cout << endl;
	}

	return 0;
}