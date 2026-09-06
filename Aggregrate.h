#ifndef AGGREGRATE_H
#define AGGREGRATE_H
#include "EmergencyIterator.h"
#include <string>

class Aggregrate {


public:
	virtual EmergencyIterator* createAllIterator() = 0;

	virtual EmergencyIterator* createAvailableIterator() = 0;
};

#endif
