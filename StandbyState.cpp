#include "StandbyState.h"
#include "EmergencyUnit.h"
#include "EnRouteState.h"

StandbyState* StandbyState::instance = nullptr;

StandbyState* StandbyState::getInstance() {
	if (instance == nullptr) {
		instance = new StandbyState();
	}
	return instance;
}

string StandbyState::getStateName() {
	return "Standby";
}

bool StandbyState::isAvailable() {
	return true;
}

void StandbyState::advance(EmergencyUnit* u) {
	u->setState(EnRouteState::getInstance());
}
