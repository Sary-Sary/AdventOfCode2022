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

std::string Compartment::operator/(const Compartment& other) {

	size_t size_one = items.size();
	size_t size_two = other.items.size();
	size_t i = 0;
	size_t j = 0;

	std::string shared_items;

	while (i < size_one && j < size_two) {

		if (items[i] == other.items[j]) {

			shared_items += items[i];
			i++;
			j++;
			
		}

		else if (items[i] < other.items[j]) i++;
		else j++;

	}

	return shared_items;

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
