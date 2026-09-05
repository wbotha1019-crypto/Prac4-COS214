#ifndef AERIALDECORATOR_H
#define AERIALDECORATOR_H
#include "UnitDecorator.h"
#include <string>

class AerialDecorator : public UnitDecorator {

private:
	string droneModel;
	int flightTime;

public:
	AerialDecorator(EmergencyComponent* c);

	void execute();

	string getStatus();

	void aerialReconnaissance();

	void droneSupport();

	void thermalImaging();

	string getDroneInfo();
};

#endif
