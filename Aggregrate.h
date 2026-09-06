#ifndef AGGREGRATE_H
#define AGGREGRATE_H

#include <string>
using namespace std;

// FIX: forward-declare instead of #include "EmergencyIterator.h" (only pointers
// are used) -- breaks the circular include with EmergencyComponent.h.
class EmergencyIterator;

class Aggregrate {
public:
	virtual EmergencyIterator* createAllIterator() = 0;
	virtual EmergencyIterator* createAvailableIterator() = 0;
	// FIX: the UML gives EmergencyComponent all three factory methods and calls
	// it the Aggregate participant, but this interface was only declaring two of
	// them. Added the third so EmergencyComponent's declaration is a genuine
	// override of the interface, not just a lookalike.
	virtual EmergencyIterator* createTypeFilterIterator(string unitType) = 0;
	virtual ~Aggregrate() {}
};
#endif
