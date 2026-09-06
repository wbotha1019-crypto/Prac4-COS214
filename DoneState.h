#ifndef DONESTATE_H
#define DONESTATE_H
#include "UnitState.h"
#include <string>
using namespace std;

class EmergencyUnit;

class DoneState : public UnitState {
private:
	static DoneState* instance;
	DoneState() {}
	DoneState(const DoneState&) = delete;
	DoneState& operator=(const DoneState&) = delete;
public:
	static DoneState* getInstance();
	string getStateName();
	bool isAvailable();
	void advance(EmergencyUnit* u);
	void reset(EmergencyUnit* u);
};
#endif