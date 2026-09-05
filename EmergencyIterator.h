#ifndef EMERGENCYITERATOR_H
#define EMERGENCYITERATOR_H
#include "Iterator.h"
#include "EmergencyComponent.h"
#include <vector>
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;


class EmergencyIterator : Iterator {

protected:
	size_t position;
	vector<EmergencyComponent*> items;

public:
	virtual ~EmergencyIterator();
	bool hasNext();
	EmergencyComponent* next();
	void reset();
	virtual void buildList(EmergencyComponent* root) = 0;
};

#endif
