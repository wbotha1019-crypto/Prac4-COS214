#include "Ambulance.h"
#include <iostream>
using namespace std;

Ambulance::Ambulance(string name, int capacity, int patientCapacity)
	: EmergencyUnit(name, "Ambulance", capacity),
	  patientCapacity(patientCapacity),
	  medicalSupplies(100) {
}

void Ambulance::performAction() {
	treatPatient();
	transportPatient();
}

void Ambulance::transportPatient() {
	cout << unitID << " transporting patient (capacity " << patientCapacity << ")" << endl;
}

void Ambulance::treatPatient() {
	if (medicalSupplies >= 10) medicalSupplies -= 10;
	cout << unitID << " treating patient (supplies left " << medicalSupplies << ")" << endl;
}

int Ambulance::getPatientCapacity() {
	return patientCapacity;
}

int Ambulance::getMedicalSupplies() {
	return medicalSupplies;
}
