#ifndef STANDBYSTATE_H
#define STANDBYSTATE_H
#include "UnitState.h"
#include "EmergencyUnit.h"

class StandbyState : UnitState {


public:
	StandbyState* static_getInstance();

	string getStateName();

	bool isAvailable();

	void advance(EmergencyUnit* u);

	void cancel(EmergencyUnit* u);
};

#endif
