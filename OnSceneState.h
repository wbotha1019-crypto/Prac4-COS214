#ifndef ONSCENESTATE_H
#define ONSCENESTATE_H
#include "UnitState.h"
#include "EmergencyUnit.h"

class OnSceneState : UnitState {


public:
	OnSceneState* static_getInstance();

	string getStateName();

	bool isAvailable();

	void advance(EmergencyUnit* u);

	void cancel(EmergencyUnit* u);
};

#endif
