#ifndef EMERGENCYITERATOR_H
#define EMERGENCYITERATOR_H
#include "Iterator.h"
#include <vector>
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

// FIX: forward-declare instead of #include "EmergencyComponent.h" — only
// pointers are used at this level (breaks the header cycle noted in Iterator.h).
class EmergencyComponent;

// FIX: was "class EmergencyIterator : Iterator" (private inheritance). Private
// inheritance is not "is-a": an EmergencyIterator* could not be used anywhere an
// Iterator* is expected, which defeats the point of having the interface at all.
class EmergencyIterator : public Iterator {
protected:
	size_t position;
	vector<EmergencyComponent*> items;
public:
	EmergencyIterator();
	virtual ~EmergencyIterator();
	bool hasNext();
	EmergencyComponent* next();
	void reset();
	virtual void buildList(EmergencyComponent* root) = 0;
};
#endif
