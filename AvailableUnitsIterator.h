#ifndef AVAILABLEUNITSITERATOR_H
#define AVAILABLEUNITSITERATOR_H
#include "EmergencyIterator.h"
#include "EmergencyComponent.h"

// FIX: private -> public inheritance (see AllUnitsIterator.h for why).
class AvailableUnitsIterator : public EmergencyIterator {


public:
	AvailableUnitsIterator(EmergencyComponent* root);

	void buildList(EmergencyComponent* root);
};

#endif
