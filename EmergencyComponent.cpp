#include "EmergencyComponent.h"

EmergencyComponent::EmergencyComponent(string name, int priority)
	: name(name), priority(priority) {
}

EmergencyComponent::~EmergencyComponent() {
	// Nothing owned directly at this level; derived classes own their own data
	// (EmergencyGroup owns children, UnitDecorator owns wrapped).
}

string EmergencyComponent::getName() {
	return name;
}

int EmergencyComponent::getPriority() {
	return priority;
}

void EmergencyComponent::setPriority(int p) {
	priority = p;
}
