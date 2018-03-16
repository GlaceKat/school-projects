#ifndef STABLE
#define STABLE
#include "HORSE.h"

const int HORSE_LIMIT = 10;

class Stable {

public:
	Stable();

	void addHorse(HorseInfo horse);
	HorseInfo removeHorse();

	int getNumHorses();

	void PrintAll();

private:

	HorseInfo stalls[HORSE_LIMIT];
	int numHorses = 0;

};

#endif