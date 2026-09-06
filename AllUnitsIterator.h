#ifndef ALLUNITSITERATOR_H
#define ALLUNITSITERATOR_H
#include "EmergencyIterator.h"
#include "EmergencyComponent.h"

// FIX: was "class AllUnitsIterator : EmergencyIterator" (private inheritance) —
// changed to public so it genuinely satisfies the Iterator/EmergencyIterator
// interface polymorphically (needed since createAllIterator() returns it via an
// EmergencyIterator* base pointer).
class AllUnitsIterator : public EmergencyIterator {
public:
	AllUnitsIterator(EmergencyComponent* root);
	void buildList(EmergencyComponent* root);
};
#endif
