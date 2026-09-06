#ifndef UNITSTATE_H
#define UNITSTATE_H
#include <string>
using namespace std;

class EmergencyUnit;

class UnitState {
public:
	virtual string getStateName() = 0;
	virtual ~UnitState() {}

	virtual bool isAvailable() = 0;
	virtual void advance(EmergencyUnit* u) = 0;

	// FIX: the stub declared this as a plain, non-virtual method here
	// AND redeclared an identical non-virtual "void cancel(EmergencyUnit* u);"
	// in every single concrete state header. Since the base version wasn't
	// virtual, those redeclarations were dead code: calling cancel() through a
	// UnitState* base pointer (which is how EmergencyUnit uses it) would always
	// run UnitState::cancel(), never a "derived override", regardless of which
	// concrete state the unit was actually in.
	// Per the Task 1 design doc, cancelling means the same thing from every
	// state (move to Done), so one shared, virtual implementation here is
	// correct — I removed the redundant redeclarations from every concrete
	// state class instead of pretending they did something.
	virtual void cancel(EmergencyUnit* u);
};
#endif
