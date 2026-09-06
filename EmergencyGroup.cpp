#include "EmergencyGroup.h"
#include "AllUnitsIterator.h"
#include "AvailableUnitsIterator.h"
#include "TypeFilterIterator.h"
#include <sstream>

EmergencyGroup::EmergencyGroup(string name, int priority)
	: EmergencyComponent(name, priority) {
}

EmergencyGroup::~EmergencyGroup() {
	// Ownership rule (Task 1, Decision 5): a group owns every child pointer it
	// holds and deletes them all on destruction. If a child was legitimately
	// handed off via transferChild()/removeChild() beforehand, it is no longer
	// in this vector and will NOT be double-deleted.
	for (size_t i = 0; i < children.size(); i++) {
		delete children[i];
	}
	children.clear();
}

void EmergencyGroup::addChild(EmergencyComponent* c) {
	if (c == nullptr) return;
	children.push_back(c);
}

EmergencyComponent* EmergencyGroup::removeChild(EmergencyComponent* c) {
	for (size_t i = 0; i < children.size(); i++) {
		if (children[i] == c) {
			children.erase(children.begin() + i);
			return c; // ownership transferred to the caller — NOT deleted here
		}
	}
	return nullptr; // not found: handled sensibly, no crash
}

bool EmergencyGroup::transferChild(EmergencyComponent* c, EmergencyGroup* newParent) {
	if (newParent == nullptr) return false;
	EmergencyComponent* removed = removeChild(c);
	if (removed == nullptr) return false; // c wasn't actually our child
	newParent->addChild(removed);
	return true;
}

void EmergencyGroup::execute() {
	for (size_t i = 0; i < children.size(); i++) {
		children[i]->execute();
	}
}

void EmergencyGroup::advance() {
	for (size_t i = 0; i < children.size(); i++) {
		children[i]->advance();
	}
}

void EmergencyGroup::cancel() {
	for (size_t i = 0; i < children.size(); i++) {
		children[i]->cancel();
	}
}

string EmergencyGroup::getStatus() {
	ostringstream oss;
	oss << "[Group: " << name << "] (" << children.size() << " children)\n";
	for (size_t i = 0; i < children.size(); i++) {
		oss << "  " << children[i]->getStatus() << "\n";
	}
	return oss.str();
}

int EmergencyGroup::getCapacity() {
	int total = 0;
	for (size_t i = 0; i < children.size(); i++) {
		total += children[i]->getCapacity();
	}
	return total;
}

int EmergencyGroup::getCurrentLoad() {
	int total = 0;
	for (size_t i = 0; i < children.size(); i++) {
		total += children[i]->getCurrentLoad();
	}
	return total;
}

int EmergencyGroup::getChildrenCount() {
	return (int)children.size();
}

// --- Iterator factory methods (Aggregate role) ---
// These build a SNAPSHOT: buildList() walks the tree once, at iterator
// creation time, and copies the relevant EmergencyComponent* pointers into the
// iterator's own vector. After that, the iterator has no further connection to
// this EmergencyGroup — later addChild/removeChild/transferChild calls on the
// live tree do NOT retroactively change an iterator that already exists.
// Consequence the team must respect: don't delete a component while a live
// iterator might still hold a pointer to it (finish or discard the iterator
// first, or take a snapshot copy of what you need before deleting).
EmergencyIterator* EmergencyGroup::createAllIterator() {
	return new AllUnitsIterator(this);
}

EmergencyIterator* EmergencyGroup::createAvailableIterator() {
	return new AvailableUnitsIterator(this);
}

EmergencyIterator* EmergencyGroup::createTypeFilterIterator(string unitType) {
	return new TypeFilterIterator(this, unitType);
}

bool EmergencyGroup::isAvailable() {
	// A group is "available" if it has at least one available unit somewhere
	// beneath it — a reasonable domain reading of "can this section still take
	// on work?" without needing to know concrete leaf types.
	for (size_t i = 0; i < children.size(); i++) {
		if (children[i]->isAvailable()) return true;
	}
	return false;
}

string EmergencyGroup::getUnitType() {
	// Groups aren't a "unit type" in the domain sense; this only exists to
	// satisfy the Component interface. TypeFilterIterator never surfaces a
	// group anyway, since populate() recurses through groups instead of
	// collecting them (see below).
	return "Group";
}

void EmergencyGroup::populate(vector<EmergencyComponent*>& list) {
	// This IS the traversal mechanism — recurse via virtual calls instead of
	// handing out `children` itself (Rule 7: no exposing the container).
	for (size_t i = 0; i < children.size(); i++) {
		children[i]->populate(list);
	}
}
