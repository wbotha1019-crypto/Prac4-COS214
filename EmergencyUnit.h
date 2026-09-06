#ifndef EMERGENCYUNIT_H
#define EMERGENCYUNIT_H
#include "EmergencyComponent.h"
#include <string>
using namespace std;

class UnitState;
class EmergencyIterator;

// FIX: was "class EmergencyUnit : EmergencyComponent" (private inheritance).
// This is the most consequential bug in the whole stub: with private
// inheritance, an EmergencyUnit* (or any subclass of it) could NOT be stored
// as, or used through, an EmergencyComponent* -- which is exactly how
// EmergencyGroup's children vector and every iterator are typed. The Composite
// pattern simply would not compile as intended. Changed to public.
class EmergencyUnit : public EmergencyComponent {
protected:
	string unitType;
	int capacity;
	int currentLoad;
	string unitID;
	// FIX: declared in the UML ("#UnitState* currentState") but missing from
	// the generated header entirely.
	UnitState* currentState;
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
	void populate(vector<EmergencyComponent*>& list);
	virtual void performAction() = 0;
};
#endif
