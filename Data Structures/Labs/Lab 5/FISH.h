#ifndef FISHINFO
#define FISHINFO
#include "ANIMAL.h"


class FishInfo : public AnimalCross {

public:

	FishInfo();

	FishInfo(string someBreed, string someHome, string someType);

	void animalMovement();
	void animalEat();

	//function to SET the NEW attribute in fish
	void setType(string fishType);

	//function to GET the NEW attribute in fish
	string getType();

private:
	string fishType;

};

#endif