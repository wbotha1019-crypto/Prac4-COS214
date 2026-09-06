#include "K9Decorator.h"
#include <iostream>
using namespace std;

K9Decorator::K9Decorator(EmergencyComponent* c)
	: UnitDecorator(c), dogBreed("German Shepherd"), dogName("Rex") {
}

void K9Decorator::execute() {
	// "Delegates + adds own behaviour": call the decorator chain underneath
	// first, then layer this decorator's extra capability on top. Because this
	// calls UnitDecorator::execute() (not wrapped->execute() directly), a
	// stack like K9Decorator -> AerialDecorator -> Ambulance still runs every
	// layer in order.
	UnitDecorator::execute();
	searchAndRescue();
}

string K9Decorator::getStatus() {
	return UnitDecorator::getStatus() + " +K9[" + dogName + "/" + dogBreed + "]";
}

void K9Decorator::searchAndRescue() {
	cout << "  (K9 " << dogName << ") searching for survivors" << endl;
}

void K9Decorator::tracking() {
	cout << "  (K9 " << dogName << ") tracking scent trail" << endl;
}

void K9Decorator::detectSubstances() {
	cout << "  (K9 " << dogName << ") detecting hazardous substances" << endl;
}

string K9Decorator::getDogInfo() {
	return dogName + " (" + dogBreed + ")";
}
