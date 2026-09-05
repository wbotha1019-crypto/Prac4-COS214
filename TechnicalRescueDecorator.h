#ifndef TECHNICALRESCUEDECORATOR_H
#define TECHNICALRESCUEDECORATOR_H
#include "UnitDecorator.h"
#include <string>

class TechnicalRescueDecorator : public UnitDecorator {

private:
	string equipmentList;
	
public:
	TechnicalRescueDecorator(EmergencyComponent* c);

	void execute();

	string getStatus();

	void ropeRescue();

	void confinedSpace();

	void extrication();

	void heavyLifting();

	string getEquipment();
};

#endif
