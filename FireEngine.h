#ifndef FIREENGINE_H
#define FIREENGINE_H
#include "EmergencyUnit.h"
#include <string>
#include <iostream>
using namespace std;

class FireEngine : EmergencyUnit {

private:
	int waterCapacity;
	int foamLevel;

public:
	FireEngine(string name, int capacity, int waterCapacity);

	void performAction();

	void extinguish();

	void deployHose();

	int getWaterCapacity();

	int getFoamLevel();
};

#endif
