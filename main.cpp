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

void report(string heading, EmergencyIterator* it)
{
	cout << heading << endl;
	while (it->hasNext())
	{
		cout << "  " << it->next()->getStatus() << endl;
	}
	cout << endl;
	delete it;
}

void buildingCollapse(EmergencyGroup* command)
{
	cout << "--- Incident 1: structural collapse, Church Street ---" << endl << endl;

	EmergencyGroup* operations = new EmergencyGroup("Operations");
	EmergencyGroup* strikeTeam = new EmergencyGroup("Strike Team Alpha");
	EmergencyGroup* medical = new EmergencyGroup("Medical Branch");

	FireEngine* engine7 = new FireEngine("Engine 7", 4, 2000);
	RescueUnit* rescue1 = new RescueUnit("Rescue 1", 4, 50);
	PoliceUnit* unit12 = new PoliceUnit("Unit 12", 2, 2);
	Ambulance* medic3 = new Ambulance("Medic 3", 2, 2);
	Ambulance* medic5 = new Ambulance("Medic 5", 2, 2);

	strikeTeam->addChild(engine7);
	strikeTeam->addChild(rescue1);
	operations->addChild(strikeTeam);
	operations->addChild(unit12);
	medical->addChild(medic3);
	medical->addChild(medic5);
	command->addChild(operations);
	command->addChild(medical);

	cout << "Call received. Resources assigned:" << endl;
	cout << command->getStatus() << endl << endl;

	cout << "Dispatching Strike Team Alpha and Unit 12." << endl;
	strikeTeam->advance();
	unit12->advance();
	report("Units still available for other calls:", command->createAvailableIterator());

	cout << "Strike Team arrives on scene." << endl;
	strikeTeam->advance();
	strikeTeam->execute();
	cout << endl;

	cout << "Survivors reported trapped. K9 team attached to Rescue 1." << endl;
	EmergencyComponent* raw = strikeTeam->removeChild(rescue1);
	EmergencyComponent* k9Rescue = new K9Decorator(raw);
	strikeTeam->addChild(k9Rescue);
	k9Rescue->execute();
	cout << endl;

	cout << "Medic 3 dispatched, then stood down when Medic 5 is closer." << endl;
	medic3->advance();
	medic3->cancel();
	medic5->advance();
	medic5->advance();
	medic5->execute();
	cout << endl;

	cout << "Engine 7 completes its work and returns to the pool." << endl;
	engine7->advance();
	engine7->advance();
	engine7->advance();
	engine7->advance();
	engine7->reset();
	cout << endl;

	cout << "Medic 5 is still on scene, Medic 3 is stood down." << endl;
	medic5->reset();
	medic3->reset();
	cout << endl;

	cout << "End of incident 1:" << endl;
	cout << command->getStatus() << endl << endl;
}

void wildfire(EmergencyGroup* command)
{
	cout << "--- Incident 2: veld fire, Bronkhorstspruit road ---" << endl << endl;

	EmergencyGroup* operations = new EmergencyGroup("Operations");
	EmergencyGroup* strikeTeam = new EmergencyGroup("Strike Team Bravo");
	EmergencyGroup* airOps = new EmergencyGroup("Air Operations");

	FireEngine* engine2 = new FireEngine("Engine 2", 4, 3000);
	FireEngine* engine9 = new FireEngine("Engine 9", 4, 2500);
	PoliceUnit* unit4 = new PoliceUnit("Unit 4", 2, 3);
	RescueUnit* rescue2 = new RescueUnit("Rescue 2", 4, 30);

	EmergencyComponent* droneRescue = new AerialDecorator(new TechnicalRescueDecorator(rescue2));

	strikeTeam->addChild(engine2);
	strikeTeam->addChild(engine9);
	operations->addChild(strikeTeam);
	operations->addChild(unit4);
	airOps->addChild(droneRescue);
	command->addChild(operations);
	command->addChild(airOps);

	cout << "Initial deployment:" << endl;
	cout << command->getStatus() << endl << endl;

	EmergencyIterator* beforeMove = strikeTeam->createAllIterator();

	cout << "Fire jumps the road. Unit 4 reassigned from Operations into Strike Team Bravo." << endl;
	operations->transferChild(unit4, strikeTeam);
	cout << "Operations now has " << operations->getChildrenCount()
	     << " child, Strike Team Bravo has " << strikeTeam->getChildrenCount() << "." << endl << endl;

	report("Strike Team Bravo iterator created before the move (snapshot):", beforeMove);
	report("Strike Team Bravo iterator created after the move:", strikeTeam->createAllIterator());

	cout << "All engines ordered to advance together." << endl;
	EmergencyIterator* engines = command->createTypeFilterIterator("FireEngine");
	while (engines->hasNext())
	{
		engines->next()->advance();
	}
	delete engines;
	report("Fire engines:", command->createTypeFilterIterator("FireEngine"));

	cout << "Air Operations conducts reconnaissance while ground crews work." << endl;
	airOps->advance();
	airOps->advance();
	airOps->execute();
	cout << endl;

	cout << "Strike Team Bravo on scene and working." << endl;
	strikeTeam->advance();
	strikeTeam->execute();
	cout << endl;

	cout << "Engine 9 is withdrawn to cover a second call." << endl;
	engine9->cancel();
	report("Units available for the second call:", command->createAvailableIterator());

	cout << "End of incident 2:" << endl;
	cout << command->getStatus() << endl;
	cout << "Total capacity " << command->getCapacity()
	     << ", current load " << command->getCurrentLoad() << endl << endl;
}

int main()
{
	EmergencyGroup* command1 = new EmergencyGroup("Incident Command 1");
	buildingCollapse(command1);
	delete command1;

	EmergencyGroup* command2 = new EmergencyGroup("Incident Command 2");
	wildfire(command2);
	delete command2;

	return 0;
}