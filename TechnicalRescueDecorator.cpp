#include "TechnicalRescueDecorator.h"
#include <iostream>
using namespace std;

TechnicalRescueDecorator::TechnicalRescueDecorator(EmergencyComponent* c)
	: UnitDecorator(c), equipmentList("hydraulic spreaders, rope kit") {
}

void TechnicalRescueDecorator::execute() {
	UnitDecorator::execute();
	extrication();
}

string TechnicalRescueDecorator::getStatus() {
	return UnitDecorator::getStatus() + " +TechRescue[" + equipmentList + "]";
}

void TechnicalRescueDecorator::ropeRescue() {
	cout << "  (TechRescue) performing rope rescue" << endl;
}

void TechnicalRescueDecorator::confinedSpace() {
	cout << "  (TechRescue) entering confined space" << endl;
}

void TechnicalRescueDecorator::extrication() {
	cout << "  (TechRescue) heavy extrication using " << equipmentList << endl;
}

void TechnicalRescueDecorator::heavyLifting() {
	cout << "  (TechRescue) heavy lifting operation" << endl;
}

string TechnicalRescueDecorator::getEquipment() {
	return equipmentList;
}
