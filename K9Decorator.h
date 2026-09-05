#ifndef K9DECORATOR_H
#define K9DECORATOR_H
#include "UnitDecorator.h"
#include <string>

class K9Decorator : public UnitDecorator {

private:
	string dogBreed;
	string dogName;

public:
	K9Decorator(EmergencyComponent* c);

	void execute();

	string getStatus();

	void searchAndRescue();

	void tracking();

	void detectSubstances();

	string getDogInfo();
};

#endif
