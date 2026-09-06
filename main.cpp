#include <iostream>
#include "EmergencyGroup.h"
#include "FireEngine.h"
#include "Ambulance.h"
#include "PoliceUnit.h"
#include "RescueUnit.h"
#include "K9Decorator.h"
#include "AerialDecorator.h"
#include "TechnicalRescueDecorator.h"
#include "EmergencyIterator.h"
using namespace std;

int main()
{
	EmergencyGroup* command = new EmergencyGroup("Incident Command");
	EmergencyGroup* operations = new EmergencyGroup("Operations");
	EmergencyGroup* strikeTeam = new EmergencyGroup("Strike Team Alpha");

	FireEngine* engine1 = new FireEngine("Engine 7", 4, 2000);
	Ambulance* amb1 = new Ambulance("Medic 3", 2, 2);
	PoliceUnit* police1 = new PoliceUnit("Unit 12", 2, 2);
	RescueUnit* rescue1 = new RescueUnit("Rescue 1", 4, 50);

	EmergencyComponent* k9Rescue = new K9Decorator(rescue1);
	EmergencyComponent* stackedAmb = new AerialDecorator(new TechnicalRescueDecorator(amb1));

	strikeTeam->addChild(engine1);
	strikeTeam->addChild(k9Rescue);
	operations->addChild(strikeTeam);
	operations->addChild(police1);
	command->addChild(operations);
	command->addChild(stackedAmb);

	cout << command->getStatus() << endl;

	EmergencyIterator* all = command->createAllIterator();
	EmergencyIterator* available = command->createAvailableIterator();
	EmergencyIterator* fireOnly = command->createTypeFilterIterator("FireEngine");

	while (all->hasNext())
	{
		cout << all->next()->getStatus() << endl;
	}
	cout << endl;

	while (available->hasNext())
	{
		cout << available->next()->getStatus() << endl;
	}
	cout << endl;

	while (fireOnly->hasNext())
	{
		cout << fireOnly->next()->getStatus() << endl;
	}
	cout << endl;

	engine1->advance();
	engine1->advance();
	engine1->execute();
	engine1->advance();
	engine1->advance();
	engine1->advance();
	engine1->advance();
	cout << engine1->getStatus() << endl;

	police1->reset();
	engine1->reset();
	cout << engine1->getStatus() << endl;

	amb1->advance();
	amb1->cancel();
	cout << amb1->getStatus() << endl;
	cout << endl;

	k9Rescue->execute();
	stackedAmb->execute();
	cout << endl;

	operations->transferChild(police1, strikeTeam);
	cout << command->getStatus() << endl;
	cout << "Capacity: " << command->getCapacity() << " Load: " << command->getCurrentLoad() << endl;

	delete all;
	delete available;
	delete fireOnly;
	delete command;

	return 0;
}