#ifndef TYPEFILTERITERATOR_H
#define TYPEFILTERITERATOR_H
#include "EmergencyIterator.h"
#include "EmergencyComponent.h"
#include <string>

class TypeFilterIterator : EmergencyIterator {

public:
	int string_wantedType;

	TypeFilterIterator(EmergencyComponent* root, string wantedType);

	void buildList(EmergencyComponent* root);

	void setWantedType(string type);
};

#endif
