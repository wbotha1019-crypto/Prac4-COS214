#ifndef AVAILABLEUNITSITERATOR_H
#define AVAILABLEUNITSITERATOR_H
#include "EmergencyIterator.h"
#include "EmergencyComponent.h"

class AvailableUnitsIterator : EmergencyIterator {


public:
	AvailableUnitsIterator(EmergencyComponent* root);

	void buildList(EmergencyComponent* root);
};

#endif
