#ifndef EMERGENCYCOMPONENT_H
#define EMERGENCYCOMPONENT_H
#include <string>
#include <iostream>
#include <vector>
#include "Aggregate.h"
using namespace std;

class EmergencyIterator;

class EmergencyComponent : public Aggregate {
protected:
	string name;
	int priority;
public:
	EmergencyComponent(string name, int priority = 0);
	virtual ~EmergencyComponent();
	string getName();
	int getPriority();
	void setPriority(int p);
	virtual void execute() = 0;
	virtual void advance() = 0;
	virtual void cancel() = 0;
	virtual void reset() = 0;
	virtual string getStatus() = 0;
	virtual int getCapacity() = 0;
	virtual int getCurrentLoad() = 0;
	virtual EmergencyIterator* createAllIterator() = 0;
	virtual EmergencyIterator* createAvailableIterator() = 0;
	virtual EmergencyIterator* createTypeFilterIterator(string unitType) = 0;

	// FIX (deviation from the generated stub, please mirror in the class diagram):
	// Composite/Decorator/Iterator only work together here without dynamic_cast or
	// type-checks (Rule 8) if the base Component exposes whatever the traversal
	// needs. These three were missing from the UML at this level:
	//   - isAvailable(): needed so AvailableUnitsIterator can filter a mixed list
	//     of EmergencyUnit* and decorated UnitDecorator* through one interface.
	//   - getUnitType(): same reasoning, for TypeFilterIterator.
	//   - populate(): the actual Composite/Iterator collaboration hook. Instead of
	//     an Iterator ever touching EmergencyGroup's children vector directly
	//     (which Rule 7 forbids), each component knows how to add *itself* (a
	//     leaf/decorated item) or recurse into its children, into the caller's
	//     list. This is virtual dispatch, not a type check.
	virtual bool isAvailable() = 0;
	virtual string getUnitType() = 0;
	virtual void populate(vector<EmergencyComponent*>& list) = 0;
};
#endif