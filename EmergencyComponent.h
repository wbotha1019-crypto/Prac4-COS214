#ifndef EMERGENCYCOMPONENT_H
#define EMERGENCYCOMPONENT_H
#include <string>
#include <iostream>
using namespace std;

class EmergencyIterator;

class EmergencyComponent {

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

	virtual string getStatus() = 0;

	virtual int getCapacity() = 0;

	virtual int getCurrentLoad() = 0;

	virtual EmergencyIterator* createAllIterator() = 0;

	virtual EmergencyIterator* createAvailableIterator() = 0;

	virtual EmergencyIterator* createTypeFilterIterator(string unitType) = 0;
};

#endif
