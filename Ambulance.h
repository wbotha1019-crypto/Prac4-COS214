#ifndef AMBULANCE_H
#define AMBULANCE_H
#include "EmergencyUnit.h"
#include <string>
#include <iostream>
using namespace std;

class Ambulance : EmergencyUnit {

private:
	int int_patientCapacity;
	int int_medicalSupplies;

public:
	Ambulance(string name, int capacity, int patientCapacity);

	void performAction();

	void transportPatient();

	void treatPatient();

	int getPatientCapacity();

	int getMedicalSupplies();
};

#endif
