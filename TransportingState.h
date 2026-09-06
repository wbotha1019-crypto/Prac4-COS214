#ifndef TRANSPORTINGSTATE_H
#define TRANSPORTINGSTATE_H
#include "UnitState.h"
#include <string>
using namespace std;

class EmergencyUnit;

class TransportingState : public UnitState {
private:
	static TransportingState* instance;
	TransportingState() {}
	TransportingState(const TransportingState&) = delete;
	TransportingState& operator=(const TransportingState&) = delete;
public:
	static TransportingState* getInstance();
	string getStateName();
	bool isAvailable();
	void advance(EmergencyUnit* u);
};
#endif
