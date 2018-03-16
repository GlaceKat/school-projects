#include <iostream>
#include "ANIMALCOLLECTION.h"
#include "ANIMALCOLLECTION.cpp"
#include "FISH.h"
#include "EXCEPTIONS.h"

using namespace std;

int main() {

	int prompt = 0;

	AnimalCollection<FishInfo> yourStable;

	while (prompt != 4) {
		cout << "Press 1 to add a fish to the collection. \n";
		cout << "Press 2 to remove a fish from the collection. \n";
		cout << "Press 3 to see how many fish are currently in the collection.\n";
		cout << "Press 4 to quit. \n";
			cin >> prompt;

		switch (prompt) {
		case 1: { //adds a fish to collection
			string pattern, breed, home;
			cout << "Enter the fish pattern: ";
			cin >> pattern;
			cout << "Enter the fish breed: ";
			cin >> breed;
			cout << "Enter the fish's home: ";
			cin >> home;

			FishInfo fish(breed, home, pattern);

			try {
				yourStable.addAnimal(fish);
			}
			catch (FullStable) {
				cout << "The collection is full!" << endl;
			}
			break;
		}

		case 2: {  //removes a fish from collection
			try {
				FishInfo fish = yourStable.removeAnimal();
				fish.printAll();
				cout << "Pattern: " << fish.getType() << endl;
			}
			catch (EmptyStable) {
				cout << "The collection is empty!" << endl;
			}
			break;
		}

		case 3: {  //sees # of horses in the stable
			cout << "There are " << yourStable.getNumAnimals() << " in the collection.\n";
			break;
		}

		case 4: {  //quits the program
			break;
		}
		default: {  //if the input is anything other than 1,2,3, or 4
			cout << "This is not a valid output.";
		}
		}
	}

	return 0;
}