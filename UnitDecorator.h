#ifndef UNITDECORATOR_H
#define UNITDECORATOR_H
#include "EmergencyComponent.h"
#include "EmergencyIterator.h"
#include <string>
#include <iostream>
using namespace std;

class UnitDecorator : public EmergencyComponent {


protected:
	EmergencyComponent* wrapped;	

public:
	UnitDecorator(EmergencyComponent* c);
	virtual ~UnitDecorator();

	string getName();
	void execute();
	void advance();
	void cancel();
	string getStatus();
	int getCapacity();
	int getCurrentLoad();

	EmergencyIterator* createAllIterator();
	EmergencyIterator* createAvailableIterator();
	EmergencyIterator* createTypeFilterIterator(string unitType);
};

#endif
