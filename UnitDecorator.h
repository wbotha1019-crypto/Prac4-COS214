#ifndef UNITDECORATOR_H
#define UNITDECORATOR_H
#include "EmergencyComponent.h"
#include <string>
using namespace std;

class EmergencyIterator;

class UnitDecorator : public EmergencyComponent {
protected:
	EmergencyComponent* wrapped;
public:
	// FIX: the stub also declared a no-arg "UnitDecorator()" — with
	// nothing to initialise wrapped to, that constructor could only ever leave
	// wrapped dangling/uninitialised. Removed it; every decorator must wrap a
	// real component.
	UnitDecorator(EmergencyComponent* c);
	virtual ~UnitDecorator();
	string getName();
	void execute();
	void advance();
	void cancel();
	void reset();
	string getStatus();
	int getCapacity();
	int getCurrentLoad();
	EmergencyIterator* createAllIterator();
	EmergencyIterator* createAvailableIterator();
	EmergencyIterator* createTypeFilterIterator(string unitType);

	bool isAvailable();
	string getUnitType();
	void populate(vector<EmergencyComponent*>& list);
};
#endif