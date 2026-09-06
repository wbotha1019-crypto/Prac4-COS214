#ifndef TYPEFILTERITERATOR_H
#define TYPEFILTERITERATOR_H
#include "EmergencyIterator.h"
#include "EmergencyComponent.h"
#include <string>
using namespace std;

// FIX: private -> public inheritance (see AllUnitsIterator.h for why).
class TypeFilterIterator : public EmergencyIterator {
private:
	// FIX: the generated stub had "int string_wantedType;" — a mangled leftover
	// from the code-gen tool trying to encode the UML type. It should be a
	// private string field, matching "-string wantedType" in the diagram.
	string wantedType;
public:
	TypeFilterIterator(EmergencyComponent* root, string wantedType);
	void buildList(EmergencyComponent* root);
	void setWantedType(string type);
};
#endif
