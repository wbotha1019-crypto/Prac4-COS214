#ifndef DONESTATE_H
#define DONESTATE_H
#include "UnitState.h"
#include "EmergencyUnit.h"

class DoneState : UnitState {


public:
	DoneState* static_getInstance();

	string getStateName();

	bool isAvailable();

	void advance(EmergencyUnit* u);

	void cancel(EmergencyUnit* u);
};

#endif
