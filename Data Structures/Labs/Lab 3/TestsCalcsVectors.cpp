#include <iostream>
#include <string>
#include "VECTOR.h"

using namespace std;

int main() {
	double x, y, scalar; //variables to hold x/y coords, magnitude, angle, and scalars
	float mag, ang;

	char promptVar = 'y'; //basically takes in a yes or a no argument as y or n
	CalcsVectors vector1;

	cout << "What is the x value of the vector? \n";
	cin >> x;
	cout << "What is the y value of the vector? \n";
	cin >> y;

	vector1.setX(x); //checking my set functions for this first workable vector
	vector1.setY(y);

	while (promptVar == 'y' || promptVar == 'Y') {
		string optChoice;
		string xyORma;

		cout << "What operation would you like to perform? (Add/Subtract/Multiply/Divide/Equals) \n"; //prompted for operation
		cin >> optChoice;

		if (optChoice == "Add" || optChoice == "Subtract" || optChoice == "Equals") {
			cout << "Do you have the x/y coordinates or magnitude/angle of the second vector? Type either xy or ma. \n";
			cin >> xyORma;
			if (xyORma == "xy") { //if they answer that they have the coordinates

				cout << "What is the x value? \n";
				cin >> x;
				cout << "What is the y value? \n";
				cin >> y;
				CalcsVectors vector2(x, y);
				if (optChoice == "Add") { //addition is performed

					vector1 + vector2;
					vector1.printAll();

				}
				else if (optChoice == "Subtract") { //subtraction is performed

					vector1 - vector2;
					vector1.printAll();
				}
				else                              //checks if the vectors are equal (if the user inputs Equals as their operation)
					if (vector1 == vector2) {
						cout << "The vectors are equal. \n";
						vector1.printAll();
					}
					else {
						cout << "The vectors are not equal.\n";
						vector1.printAll();
					}
			}
			else if (xyORma == "ma") { //if the user wants to input magnitude and angle

				cout << "What is the magnitude of the vector? \n";
				cin >> mag;
				cout << "What is the angle of the vector? \n";
				cin >> ang;
				CalcsVectors vector2(mag, ang);
				if (optChoice == "Add") { //adds the vectors

					vector1 + vector2;
					vector1.printAll();

				}
				else if (optChoice == "Subtract") { //subtracts the vectors

					vector1 - vector2;
					vector1.printAll();
				}
				else                              //checks if the vectors are equal (if the user inputs Equals as their operator)
					if (vector1 == vector2) {
						cout << "The vectors are equal. \n";
						vector1.printAll();
					}
					else {
						cout << "The vectors are not equal.\n";
						vector1.printAll();
					}

			}
			else {                                   //somehow the user input something incorrectly
				cout << "This isn't a valid input. \n";
			}

		}
		else if (optChoice == "Multiply" || optChoice == "Divide") { //onto MULTIPLYING AND DIVIDING with a scalar
			cout << "What is the value of the scalar to be multiplied/divided?\n";
			cin >> scalar;

			if (optChoice == "Multiply") { //multiply the vector by the scalar

				vector1 * scalar;
				vector1.printAll();
			}
			else {               //This is division of the vector and scalar

				vector1 / scalar;
				vector1.printAll();
			}
		}
		else {                                       //somehow the user put something in wrong
			cout << "This isn't a valid input. \n";
		}

		cout << "Would you like to continue or try again? (y/n) \n"; //This is how we go back to step b and start over
		cin >> promptVar;

	}

	return 0;
}