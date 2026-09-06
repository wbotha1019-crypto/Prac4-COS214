#include "OnSceneState.h"
#include "EmergencyUnit.h"
#include "StabilizingState.h"

OnSceneState* OnSceneState::instance = nullptr;

OnSceneState* OnSceneState::getInstance() {
	if (instance == nullptr) {
		instance = new OnSceneState();
	}
	return instance;
}

string OnSceneState::getStateName() {
	return "On Scene";
}

bool OnSceneState::isAvailable() {
	return false;
}

void OnSceneState::advance(EmergencyUnit* u) {
	u->setState(StabilizingState::getInstance());
}
