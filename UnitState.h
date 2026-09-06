#ifndef UNITSTATE_H
#define UNITSTATE_H
#include "EmergencyUnit.h"
#include <string>
#include <iostream>
using namespace std;

class UnitState {


public:
	virtual string getStateName() = 0;
	virtual ~UnitState();
	
	virtual bool isAvailable() = 0;
	virtual void advance(EmergencyUnit* u) = 0;
	void cancel(EmergencyUnit* u);
};

#endif
