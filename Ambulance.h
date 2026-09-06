#ifndef AMBULANCE_H
#define AMBULANCE_H
#include "EmergencyUnit.h"
#include <string>
using namespace std;

// FIX: private -> public inheritance (FireEngine.h).
class Ambulance : public EmergencyUnit {
private:
	// FIX: stub had "int int_patientCapacity; int int_medicalSupplies;"
	// — mangled names from the code-gen tool. Renamed to match the UML
	// ("-int patientCapacity", "-int medicalSupplies").
	int patientCapacity;
	int medicalSupplies;
public:
	Ambulance(string name, int capacity, int patientCapacity);
	void performAction();
	void transportPatient();
	void treatPatient();
	int getPatientCapacity();
	int getMedicalSupplies();
};
#endif
