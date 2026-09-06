#include "FireEngine.h"
#include <iostream>
using namespace std;

FireEngine::FireEngine(string name, int capacity, int waterCapacity)
	: EmergencyUnit(name, "FireEngine", capacity),
	  waterCapacity(waterCapacity),
	  foamLevel(100) {
}

void FireEngine::performAction() {
	deployHose();
	extinguish();
}

void FireEngine::extinguish() {
	if (foamLevel > 0) foamLevel -= 10;
	cout << unitID << " extinguishing fire (foam level now " << foamLevel << ")" << endl;
}

void FireEngine::deployHose() {
	cout << unitID << " deploying hose (water capacity " << waterCapacity << "L)" << endl;
}

int FireEngine::getWaterCapacity() {
	return waterCapacity;
}

int FireEngine::getFoamLevel() {
	return foamLevel;
}
