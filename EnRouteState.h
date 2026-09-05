#ifndef ENROUTESTATE_H
#define ENROUTESTATE_H
#include "UnitState.h"
#include "EmergencyUnit.h"

class EnRouteState : UnitState {


public:
	EnRouteState* static_getInstance();

	string getStateName();

	bool isAvailable();

	void advance(EmergencyUnit* u);

	void cancel(EmergencyUnit* u);
};

#endif
