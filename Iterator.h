#ifndef ITERATOR_H
#define ITERATOR_H
#include "EmergencyComponent.h"
#include <string>
#include <iostream>
using namespace std;

class Iterator {


public:
	virtual bool hasNext() = 0;

	virtual EmergencyComponent* next() = 0;
};

#endif
