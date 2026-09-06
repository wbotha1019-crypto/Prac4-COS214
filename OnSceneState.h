#ifndef ONSCENESTATE_H
#define ONSCENESTATE_H
#include "UnitState.h"
#include <string>
using namespace std;

class EmergencyUnit;

class OnSceneState : public UnitState {
private:
	static OnSceneState* instance;
	OnSceneState() {}
	OnSceneState(const OnSceneState&) = delete;
	OnSceneState& operator=(const OnSceneState&) = delete;
public:
	static OnSceneState* getInstance();
	string getStateName();
	bool isAvailable();
	void advance(EmergencyUnit* u);
};
#endif
