#ifndef POLICEUNIT_H
#define POLICEUNIT_H
#include "EmergencyUnit.h"
#include <string>
using namespace std;

// FIX: private -> public inheritance (see FireEngine.h).
class PoliceUnit : public EmergencyUnit {
private:
	int officerCount;
	// FIX: the generated stub declared BOTH a field "bool hasK9;" AND a method
	// "bool hasK9();" with the identical name — that is a straight compile
	// error in C++ (a class cannot have a data member and a member function
	// sharing one name). Renamed the field to hasK9Unit; the public method
	// hasK9() below is unchanged and still matches the UML.
	bool hasK9Unit;
public:
	PoliceUnit(string name, int capacity, int officerCount);
	void performAction();
	void securePerimeter();
	void directTraffic();
	int getOfficerCount();
	bool hasK9();
};
#endif
