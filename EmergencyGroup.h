#ifndef EMERGENCYGROUP_H
#define EMERGENCYGROUP_H
#include "EmergencyComponent.h"
#include "EmergencyIterator.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class EmergencyGroup : public EmergencyComponent {


public:
	EmergencyGroup(string name, int priority = 0);
	virtual ~EmergencyGroup();

	void addChild(EmergencyComponent* c);

	EmergencyComponent* removeChild(EmergencyComponent* c);

	bool transferChild(EmergencyComponent* c, EmergencyGroup* newParent);

	void execute();

	void advance();

	void cancel();

	string getStatus();

	int getCapacity();

	int getCurrentLoad();

	EmergencyIterator* createAllIterator();

	EmergencyIterator* createAvailableIterator();

	EmergencyIterator* createTypeFilterIterator(string unitType);

	int getChildrenCount();
};

#endif
