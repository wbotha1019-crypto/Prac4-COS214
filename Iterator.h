#ifndef ITERATOR_H
#define ITERATOR_H

// FIX: only pointers to EmergencyComponent are used here, so we forward-declare
// instead of #include "EmergencyComponent.h". The original generated stub fully
// included it, which (once EmergencyComponent.h is made to implement Aggregate)
// creates a circular #include chain: EmergencyComponent.h -> Aggregate.h ->
// EmergencyIterator.h -> Iterator.h -> EmergencyComponent.h.
class EmergencyComponent;

class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual EmergencyComponent* next() = 0;
	virtual ~Iterator() {}
};
#endif