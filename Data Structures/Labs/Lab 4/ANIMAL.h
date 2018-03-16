#ifndef ANIMALCROSS
#define ANIMALCROSS
#include <string>

using namespace std;

class AnimalCross {

public:

	AnimalCross(); //default constructor
	AnimalCross(string breed, string home); //overload constructor

	virtual void animalMovement();
	void animalEat();

	//Set attributes
	void setBreed(string somebreed);
	void setHome(string someHome);

	//Get attributes
	string getBreed();
	string getHome();

	//Prints all the necessary data
	void printAll();

	string breed;
	string home;
};
#endif
