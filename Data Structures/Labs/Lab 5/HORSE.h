#ifndef HORSEINFO
#define HORSEINFO
#include "ANIMAL.h"

class HorseInfo : public AnimalCross {

public:

	HorseInfo();

	HorseInfo(string someBreed, string someHome, string someColor);

	void animalMovement();
	void animalEat();

	//function to SET the NEW attribute in horse
	void setHorseColor(string color);

	//function to GET the NEW attribute in horse
	string getHorseColor();


private:
	string horseColor;


};

#endif
