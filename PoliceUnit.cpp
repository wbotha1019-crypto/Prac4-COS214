#include "PoliceUnit.h"
#include <iostream>
using namespace std;

PoliceUnit::PoliceUnit(string name, int capacity, int officerCount)
	: EmergencyUnit(name, "PoliceUnit", capacity),
	  officerCount(officerCount),
	  hasK9Unit(false) {
}

void PoliceUnit::performAction() {
	securePerimeter();
	directTraffic();
}

void PoliceUnit::securePerimeter() {
	cout << unitID << " securing perimeter with " << officerCount << " officers" << endl;
}

void PoliceUnit::directTraffic() {
	cout << unitID << " directing traffic" << endl;
}

int PoliceUnit::getOfficerCount() {
	return officerCount;
}

bool PoliceUnit::hasK9() {
	return hasK9Unit;
}
