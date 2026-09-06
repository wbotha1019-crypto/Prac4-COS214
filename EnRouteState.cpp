#include "EnRouteState.h"
#include "EmergencyUnit.h"
#include "OnSceneState.h"

EnRouteState* EnRouteState::instance = nullptr;

EnRouteState* EnRouteState::getInstance() {
	if (instance == nullptr) {
		instance = new EnRouteState();
	}
	return instance;
}

string EnRouteState::getStateName() {
	return "En Route";
}

bool EnRouteState::isAvailable() {
	return false;
}

void EnRouteState::advance(EmergencyUnit* u) {
	u->setState(OnSceneState::getInstance());
}
