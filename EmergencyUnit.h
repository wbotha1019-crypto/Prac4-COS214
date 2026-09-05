#ifndef EMERGENCYUNIT_H
#define EMERGENCYUNIT_H
#include "EmergencyComponent.h"
#include "EmergencyIterator.h"
#include <string>
#include <iostream>
using namespace std;

class UnitState;

class EmergencyUnit : EmergencyComponent {

protected:
	string unitType;
    int capacity;
    int currentLoad;
	string unitID;

public:
	EmergencyUnit(string name, string unitType, int capacity);
	virtual ~EmergencyUnit();
	void setState(UnitState* s);

	UnitState* getState();

	string getUnitType();

	string getUnitID();

	bool isAvailable();

	void execute();

	void advance();

	void cancel();

	string getStatus();

	int getCapacity();

	int getCurrentLoad();

	EmergencyIterator* createAllIterator();

	EmergencyIterator* createAvailableIterator();

	EmergencyIterator* createTypeFilterIterator(string unitType);

	virtual void performAction() = 0;
};

#endif
