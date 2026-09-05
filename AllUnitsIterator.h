#ifndef ALLUNITSITERATOR_H
#define ALLUNITSITERATOR_H
#include "EmergencyIterator.h"
#include "EmergencyComponent.h"

class AllUnitsIterator : EmergencyIterator {


public:
	AllUnitsIterator(EmergencyComponent* root);

	void buildList(EmergencyComponent* root);
};

#endif
