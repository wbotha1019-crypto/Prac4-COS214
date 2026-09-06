#ifndef RESCUEUNIT_H
#define RESCUEUNIT_H
#include "EmergencyUnit.h"
#include <string>
#include <iostream>
using namespace std;

// FIX: private -> public inheritance (see FireEngine.h).
class RescueUnit : public EmergencyUnit {

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
