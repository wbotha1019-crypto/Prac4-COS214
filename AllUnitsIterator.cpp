#include "AllUnitsIterator.h"

AllUnitsIterator::AllUnitsIterator(EmergencyComponent* root) {
	buildList(root);
}

void AllUnitsIterator::buildList(EmergencyComponent* root) {
	items.clear();
	position = 0;
	if (root != nullptr) {
		// populate() is virtual: a group recurses over its children, a unit or
		// decorated unit adds itself. We never touch a group's internal
		// container directly (Rule 7).
		root->populate(items);
	}
}
