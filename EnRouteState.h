#ifndef ENROUTESTATE_H
#define ENROUTESTATE_H
#include "UnitState.h"
#include <string>
using namespace std;

class EmergencyUnit;

class EnRouteState : public UnitState {
private:
	static EnRouteState* instance;
	EnRouteState() {}
	EnRouteState(const EnRouteState&) = delete;
	EnRouteState& operator=(const EnRouteState&) = delete;
public:
	static EnRouteState* getInstance();
	string getStateName();
	bool isAvailable();
	void advance(EmergencyUnit* u);
};
#endif
