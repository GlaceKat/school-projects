#include <iostream>
#include "STABLE.h"
#include "HORSE.h"
#include "EXCEPTIONS.h"

using namespace std;

int main() {

	int prompt = 0;

	Stable yourStable;

	while (prompt != 4) {
		cout << "Press 1 to add a horse to the stable. \n";
		cout << "Press 2 to remove a horse from the stable. \n";
		cout << "Press 3 to see how many horses are currently in the stable.\n";
		cout << "Press 4 to quit. \n";
			cin >> prompt;

		switch (prompt) {
		case 1: { //adds a horse to stable
			string color, breed, home;
			cout << "Enter the horse color: ";
			cin >> color;
			cout << "Enter the horse breed: ";
			cin >> breed;
			cout << "Enter the horse's home: ";
			cin >> home;

			HorseInfo horse(breed, home, color);

			try {
				yourStable.addHorse(horse);
			}
			catch (FullStable) {
				cout << "The stable is full!" << endl;
			}
			break;
		}

		case 2: {  //removes a horse from stable
			try {
				HorseInfo horse = yourStable.removeHorse();
				horse.printAll();
				cout << "Color: " << horse.getHorseColor() << endl;
			}
			catch (EmptyStable) {
				cout << "The stable is empty!" << endl;
			}
			break;
		}

		case 3: {  //sees # of horses in the stable
			cout << "There are " << yourStable.getNumHorses() << " in the stable.\n";
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