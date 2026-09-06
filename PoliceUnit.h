#ifndef POLICEUNIT_H
#define POLICEUNIT_H
#include "EmergencyUnit.h"
#include <string>
#include <iostream>
using namespace std;

class PoliceUnit : EmergencyUnit {

private:
	int officerCount;
	bool hasK9;

public:
	PoliceUnit(string name, int capacity, int officerCount);

	void performAction();

	void securePerimeter();

	void directTraffic();

	int getOfficerCount();

	bool hasK9();
};

#endif
