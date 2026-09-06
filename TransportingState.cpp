#include "TransportingState.h"
#include "EmergencyUnit.h"
#include "DoneState.h"

TransportingState* TransportingState::instance = nullptr;

TransportingState* TransportingState::getInstance() {
	if (instance == nullptr) {
		instance = new TransportingState();
	}
	return instance;
}

string TransportingState::getStateName() {
	return "Transporting";
}

bool TransportingState::isAvailable() {
	return false;
}

void TransportingState::advance(EmergencyUnit* u) {
	u->setState(DoneState::getInstance());
}
