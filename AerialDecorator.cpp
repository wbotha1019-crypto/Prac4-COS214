#include "AerialDecorator.h"
#include <iostream>
using namespace std;

AerialDecorator::AerialDecorator(EmergencyComponent* c)
	: UnitDecorator(c), droneModel("DJI-Matrice"), flightTime(30) {
}

void AerialDecorator::execute() {
	UnitDecorator::execute();
	aerialReconnaissance();
}

string AerialDecorator::getStatus() {
	return UnitDecorator::getStatus() + " +Aerial[" + droneModel + "]";
}

void AerialDecorator::aerialReconnaissance() {
	cout << "  (Drone " << droneModel << ") conducting aerial reconnaissance" << endl;
}

void AerialDecorator::droneSupport() {
	cout << "  (Drone " << droneModel << ") providing overhead support" << endl;
}

void AerialDecorator::thermalImaging() {
	cout << "  (Drone " << droneModel << ") scanning with thermal imaging" << endl;
}

string AerialDecorator::getDroneInfo() {
	return droneModel + " (" + std::to_string(flightTime) + " min flight time)";
}
