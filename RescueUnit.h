#ifndef RESCUEUNIT_H
#define RESCUEUNIT_H
#include "EmergencyUnit.h"
#include <string>
#include <iostream>
using namespace std;

class RescueUnit : EmergencyUnit {

private:
	int ropeLength;
	bool hasCuttingTools;

public:
	RescueUnit(string name, int capacity, int ropeLength);

	void performAction();

	void performRescue();

	void extricate();

	int getRopeLength();
};

#endif
