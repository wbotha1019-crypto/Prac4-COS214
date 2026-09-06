#include "UnitState.h"
#include "EmergencyUnit.h"
#include "DoneState.h"
#include <iostream>
using namespace std;

void UnitState::cancel(EmergencyUnit* u) {
	if (u->getState() == DoneState::getInstance()) {
		// Invalid transition handled sensibly: cancelling an already-finished
		// unit is a no-op, not an error.
		cout << "[Cancel] " << u->getUnitID() << " is already Done; nothing to cancel." << endl;
		return;
	}
	cout << "[Cancel] " << u->getUnitID() << " mission cancelled while " << getStateName() << "." << endl;
	u->setState(DoneState::getInstance());
}
