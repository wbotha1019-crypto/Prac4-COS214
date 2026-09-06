#include "RescueUnit.h"
#include <iostream>
using namespace std;

RescueUnit::RescueUnit(string name, int capacity, int ropeLength)
	: EmergencyUnit(name, "RescueUnit", capacity),
	  ropeLength(ropeLength),
	  hasCuttingTools(true) {
}

void RescueUnit::performAction() {
	performRescue();
	extricate();
}

void RescueUnit::performRescue() {
	cout << unitID << " performing rescue (rope length " << ropeLength << "m)" << endl;
}

void RescueUnit::extricate() {
	cout << unitID << " extricating casualty" << (hasCuttingTools ? " using cutting tools" : "") << endl;
}

int RescueUnit::getRopeLength() {
	return ropeLength;
}
