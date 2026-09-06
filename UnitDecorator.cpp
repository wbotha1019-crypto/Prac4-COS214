#include "UnitDecorator.h"

UnitDecorator::UnitDecorator(EmergencyComponent* c)
	: EmergencyComponent(c ? c->getName() : "", c ? c->getPriority() : 0),
	  wrapped(c) {
}

UnitDecorator::~UnitDecorator() {
	// Ownership rule (Task 1, Decision 5): a decorator owns the component it
	// wraps and deletes it. If you stack decorators (K9Decorator wrapping an
	// AerialDecorator wrapping an Ambulance, say), each destructor deletes the
	// next one in, so the whole stack unwinds cleanly with a single `delete`
	// on the outermost decorator.
	delete wrapped;
}

string UnitDecorator::getName() {
	return wrapped->getName();
}

void UnitDecorator::execute() {
	wrapped->execute();
}

void UnitDecorator::advance() {
	wrapped->advance();
}

void UnitDecorator::cancel() {
	wrapped->cancel();
}

void UnitDecorator::reset()
{
	wrapped->reset();
}

string UnitDecorator::getStatus() {
	return wrapped->getStatus();
}

int UnitDecorator::getCapacity() {
	return wrapped->getCapacity();
}

int UnitDecorator::getCurrentLoad() {
	return wrapped->getCurrentLoad();
}

EmergencyIterator* UnitDecorator::createAllIterator() {
	return wrapped->createAllIterator();
}

EmergencyIterator* UnitDecorator::createAvailableIterator() {
	return wrapped->createAvailableIterator();
}

EmergencyIterator* UnitDecorator::createTypeFilterIterator(string unitType) {
	return wrapped->createTypeFilterIterator(unitType);
}

bool UnitDecorator::isAvailable() {
	return wrapped->isAvailable();
}

string UnitDecorator::getUnitType() {
	return wrapped->getUnitType();
}

void UnitDecorator::populate(vector<EmergencyComponent*>& list) {
	// A decorated component is treated as a single discoverable "unit-like"
	// item during traversal — it adds ITSELF (not the raw wrapped object), so
	// that calling execute()/getStatus() on the iterator's result still gets
	// the decorated behaviour, not the plain undecorated one.
	list.push_back(this);
}