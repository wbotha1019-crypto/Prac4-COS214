#include "EmergencyUnit.h"
#include "UnitState.h"
#include "StandbyState.h"
#include "DoneState.h"
#include "AllUnitsIterator.h"
#include "AvailableUnitsIterator.h"
#include "TypeFilterIterator.h"
#include <sstream>
#include <iostream>
using namespace std;

static int nextUnitSerial = 1;

EmergencyUnit::EmergencyUnit(string name, string unitType, int capacity)
	: EmergencyComponent(name, 0),
	  unitType(unitType),
	  capacity(capacity),
	  currentLoad(0),
	  currentState(StandbyState::getInstance()) {
	ostringstream oss;
	oss << unitType << "-" << nextUnitSerial++;
	unitID = oss.str();
}

EmergencyUnit::~EmergencyUnit() {
	// Ownership rule (Task 1, Decision 5): currentState points at a shared
	// singleton owned by no one in particular (its process-lifetime instance
	// lives until program exit). We must NOT delete it here.
}

void EmergencyUnit::setState(UnitState* s) {
	if (s == nullptr) return;
	currentState = s;
}

UnitState* EmergencyUnit::getState() {
	return currentState;
}

string EmergencyUnit::getUnitType() {
	return unitType;
}

string EmergencyUnit::getUnitID() {
	return unitID;
}

bool EmergencyUnit::isAvailable() {
	return currentState->isAvailable();
}

void EmergencyUnit::execute() {
	// Design decision (execute() "delegates to State"): a unit that has
	// already finished its mission has nothing left to execute. Every other
	// state is free to actually perform the domain action.
	if (currentState == DoneState::getInstance())
	{
		cout << "[Execute] " << unitID << " is Done; no action taken." << endl;
		return;
	}
	performAction();
}

void EmergencyUnit::advance() {
	currentState->advance(this);
}

void EmergencyUnit::cancel() {
	currentState->cancel(this);
}

void EmergencyUnit::reset()
{
	currentState->reset(this);
	if (currentState == StandbyState::getInstance())
	{
		currentLoad = 0;
	}
}

string EmergencyUnit::getStatus() {
	ostringstream oss;
	oss << "[Unit " << unitID << " \"" << name << "\" (" << unitType << ")] state="
	    << currentState->getStateName() << " load=" << currentLoad << "/" << capacity;
	return oss.str();
}

int EmergencyUnit::getCapacity() {
	return capacity;
}

int EmergencyUnit::getCurrentLoad() {
	return currentLoad;
}

EmergencyIterator* EmergencyUnit::createAllIterator() {
	return new AllUnitsIterator(this);
}

EmergencyIterator* EmergencyUnit::createAvailableIterator() {
	return new AvailableUnitsIterator(this);
}

EmergencyIterator* EmergencyUnit::createTypeFilterIterator(string unitType) {
	return new TypeFilterIterator(this, unitType);
}

void EmergencyUnit::populate(vector<EmergencyComponent*>& list) {
	list.push_back(this);
}