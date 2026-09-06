#ifndef STABILIZINGSTATE_H
#define STABILIZINGSTATE_H
#include "UnitState.h"
#include <string>
using namespace std;

class EmergencyUnit;

class StabilizingState : public UnitState {
private:
	static StabilizingState* instance;
	StabilizingState() {}
	StabilizingState(const StabilizingState&) = delete;
	StabilizingState& operator=(const StabilizingState&) = delete;
public:
	static StabilizingState* getInstance();
	string getStateName();
	bool isAvailable();
	void advance(EmergencyUnit* u);
};
#endif
