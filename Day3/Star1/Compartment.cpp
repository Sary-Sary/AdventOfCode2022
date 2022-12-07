#include "Compartment.h"

Compartment::Compartment() {}

Compartment::Compartment(std::string items_) {

	items = items_;
	sort_items();
}


Compartment::~Compartment() {}

char Compartment::operator[](int position) {

	return items[position];

}

Compartment Compartment::operator=(const Compartment& other) {

	items = other.items;

	return *this;

}

void Compartment::sort_items() {

	size_t size = items.size();

	for (size_t i = size - 1; i > 0; i--) {

		for (size_t j = 0; j < i; j++) {

			if (items[j] > items[j + 1]) std::swap(items[j], items[j + 1]);

		}

	}

}

size_t Compartment::size() { return items.size(); }
