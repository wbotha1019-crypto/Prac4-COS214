#ifndef STABILIZINGSTATE_H
#define STABILIZINGSTATE_H
#include "UnitState.h"
#include "EmergencyUnit.h"

class StabilizingState : UnitState {


public:
	StabilizingState* static_getInstance();

	string getStateName();

	bool isAvailable();

	void advance(EmergencyUnit* u);

	void cancel(EmergencyUnit* u);
};

#endif
