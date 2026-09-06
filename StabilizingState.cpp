#include "StabilizingState.h"
#include "EmergencyUnit.h"
#include "TransportingState.h"

StabilizingState* StabilizingState::instance = nullptr;

StabilizingState* StabilizingState::getInstance() {
	if (instance == nullptr) {
		instance = new StabilizingState();
	}
	return instance;
}

string StabilizingState::getStateName() {
	return "Stabilizing";
}

bool StabilizingState::isAvailable() {
	return false;
}

void StabilizingState::advance(EmergencyUnit* u) {
	u->setState(TransportingState::getInstance());
}
