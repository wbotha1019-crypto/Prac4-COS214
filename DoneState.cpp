#include "DoneState.h"
#include "EmergencyUnit.h"
#include <iostream>
using namespace std;

DoneState* DoneState::instance = nullptr;

DoneState* DoneState::getInstance() {
	if (instance == nullptr) {
		instance = new DoneState();
	}
	return instance;
}

string DoneState::getStateName() {
	return "Done";
}

bool DoneState::isAvailable() {
	// A unit that has finished its mission is free to be dispatched again.
	return true;
}

void DoneState::advance(EmergencyUnit* u) {
	// Invalid transition, handled sensibly: there is nothing after Done.
	cout << "[Invalid] " << u->getUnitID() << " is already Done; cannot advance further." << endl;
}
