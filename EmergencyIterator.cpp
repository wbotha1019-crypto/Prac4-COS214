#include "EmergencyIterator.h"

EmergencyIterator::EmergencyIterator() : position(0) {
}

EmergencyIterator::~EmergencyIterator() {
	// items holds borrowed pointers into the live hierarchy — this class does
	// NOT own them and must not delete them. Only the vector itself is cleaned
	// up, automatically, by ~vector.
}

bool EmergencyIterator::hasNext() {
	return position < items.size();
}

EmergencyComponent* EmergencyIterator::next() {
	if (!hasNext()) {
		// Invalid use handled sensibly rather than undefined behaviour.
		return nullptr;
	}
	return items[position++];
}

void EmergencyIterator::reset() {
	position = 0;
}
