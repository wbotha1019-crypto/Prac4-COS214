#include "AvailableUnitsIterator.h"

AvailableUnitsIterator::AvailableUnitsIterator(EmergencyComponent* root) {
	buildList(root);
}

void AvailableUnitsIterator::buildList(EmergencyComponent* root) {
	items.clear();
	position = 0;
	if (root == nullptr) return;

	vector<EmergencyComponent*> all;
	root->populate(all);
	for (size_t i = 0; i < all.size(); i++) {
		if (all[i]->isAvailable()) {
			items.push_back(all[i]);
		}
	}
}
