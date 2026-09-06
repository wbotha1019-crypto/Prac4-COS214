#include "TypeFilterIterator.h"

TypeFilterIterator::TypeFilterIterator(EmergencyComponent* root, string wantedType)
	: wantedType(wantedType) {
	buildList(root);
}

void TypeFilterIterator::buildList(EmergencyComponent* root) {
	items.clear();
	position = 0;
	if (root == nullptr) return;

	vector<EmergencyComponent*> all;
	root->populate(all);
	for (size_t i = 0; i < all.size(); i++) {
		if (all[i]->getUnitType() == wantedType) {
			items.push_back(all[i]);
		}
	}
}

void TypeFilterIterator::setWantedType(string type) {
	wantedType = type;
	// Deliberately does NOT rebuild items automatically — changing the filter
	// after construction is a distinct operation from traversing; caller must
	// call buildList() again with the same root if they want a refreshed list.
	// (Ties into our snapshot traversal policy — see EmergencyGroup.cpp.)
}
