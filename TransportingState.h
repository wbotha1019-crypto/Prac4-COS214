#ifndef TRANSPORTINGSTATE_H
#define TRANSPORTINGSTATE_H
#include "UnitState.h"
#include "EmergencyUnit.h"

class TransportingState : UnitState {


public:
	TransportingState* static_getInstance();

	string getStateName();

	bool isAvailable();

	void advance(EmergencyUnit* u);

	void cancel(EmergencyUnit* u);
};

#endif
