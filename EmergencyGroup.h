#ifndef EMERGENCYGROUP_H
#define EMERGENCYGROUP_H
#include "EmergencyComponent.h"
#include <string>
#include <vector>
using namespace std;

class EmergencyIterator;

class EmergencyGroup : public EmergencyComponent {
private:
	// FIX: the UML lists "-vector<EmergencyComponent*> children" but the
	// generated header never actually declared this field — every method that
	// should have used it (addChild, execute, getCapacity, ...) had nothing to
	// operate on. Added here, matching the diagram.
	vector<EmergencyComponent*> children;
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

	bool isAvailable();
	string getUnitType();
	void populate(vector<EmergencyComponent*>& list);
};
#endif
