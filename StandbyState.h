#ifndef STANDBYSTATE_H
#define STANDBYSTATE_H
#include "UnitState.h"
#include <string>
using namespace std;

class EmergencyUnit;

// FIX: was "class StandbyState : UnitState" (private) -> public, and the
// generated code declared a non-static member function literally named
// "static_getInstance" (the code-gen tool choked on turning UML's
// "+getInstance(): StandbyState*" static method into real C++). A singleton
// needs an actual `static` method plus a private constructor and a private
// static instance pointer, none of which existed. Fixed below and mirrored in
// every other *State.h.
class StandbyState : public UnitState {
private:
	static StandbyState* instance;
	StandbyState() {}
	StandbyState(const StandbyState&) = delete;
	StandbyState& operator=(const StandbyState&) = delete;
public:
	static StandbyState* getInstance();
	string getStateName();
	bool isAvailable();
	void advance(EmergencyUnit* u);
};
#endif
