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

int main() {
	cout << "=== Building hierarchy (4 levels below root) ===" << endl;
	EmergencyGroup* command = new EmergencyGroup("Incident Command");
	EmergencyGroup* operations = new EmergencyGroup("Operations");
	EmergencyGroup* strikeTeam = new EmergencyGroup("Strike Team Alpha");

	FireEngine* engine1 = new FireEngine("Engine 7", 4, 2000);
	Ambulance* amb1 = new Ambulance("Medic 3", 2, 2);
	PoliceUnit* police1 = new PoliceUnit("Unit 12", 2, 2);
	RescueUnit* rescue1 = new RescueUnit("Rescue 1", 4, 50);

	// Decorate one unit before it enters the tree, and stack two decorators on
	// another, to prove decoration composes with the Composite structure.
	EmergencyComponent* k9Rescue = new K9Decorator(rescue1);
	EmergencyComponent* stackedAmb = new AerialDecorator(new TechnicalRescueDecorator(amb1));

	strikeTeam->addChild(engine1);
	strikeTeam->addChild(k9Rescue);
	operations->addChild(strikeTeam);
	operations->addChild(police1);
	command->addChild(operations);
	command->addChild(stackedAmb);

	cout << "\n=== Two independent iterators over the same tree ===" << endl;
	EmergencyIterator* all1 = command->createAllIterator();
	EmergencyIterator* available = command->createAvailableIterator();

	cout << "-- All units --" << endl;
	while (all1->hasNext()) {
		cout << all1->next()->getStatus() << endl;
	}
	cout << "-- Available units only --" << endl;
	while (available->hasNext()) {
		cout << available->next()->getStatus() << endl;
	}

	cout << "\n=== Type filter, independently of the two above ===" << endl;
	EmergencyIterator* fireOnly = command->createTypeFilterIterator("FireEngine");
	while (fireOnly->hasNext()) {
		cout << fireOnly->next()->getStatus() << endl;
	}

	cout << "\n=== State transitions (valid + one invalid) ===" << endl;
	cout << engine1->getStatus() << endl;
	engine1->advance(); // Standby -> En Route
	engine1->advance(); // -> On Scene
	engine1->execute();
	cout << engine1->getStatus() << endl;
	engine1->advance(); // -> Stabilizing
	engine1->advance(); // -> Transporting
	engine1->advance(); // -> Done
	engine1->advance(); // INVALID: already Done
	cout << engine1->getStatus() << endl;

	cout << "\n=== Decorated + stacked decorator execute() ===" << endl;
	k9Rescue->execute();
	stackedAmb->execute();

	cout << "\n=== Structural change mid-run: transfer a unit between groups ===" << endl;
	bool moved = operations->transferChild(police1, strikeTeam);
	cout << "Transferred police1 into strikeTeam: " << (moved ? "yes" : "no") << endl;
	cout << "operations children now: " << operations->getChildrenCount() << endl;
	cout << "strikeTeam children now: " << strikeTeam->getChildrenCount() << endl;
	cout << "(all1/available/fireOnly snapshots above are unaffected by this change)" << endl;

	cout << "\n=== Aggregate composite status ===" << endl;
	cout << command->getStatus();
	cout << "Total capacity: " << command->getCapacity() << ", total load: " << command->getCurrentLoad() << endl;

	delete all1;
	delete available;
	delete fireOnly;
	delete command; // recursively deletes everything owned in the tree

	cout << "\n=== Done. If Valgrind shows 0 definitely lost, memory is clean. ===" << endl;
	return 0;
}
