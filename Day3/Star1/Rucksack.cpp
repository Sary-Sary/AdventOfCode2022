#include "Rucksack.h"

Rucksack::Rucksack() {}

Rucksack::Rucksack(std::string full_rucksack) {

	size_t size = full_rucksack.size();
	std::string one_;
	std::string two_;

	for (size_t i = 0; i < size; i++) {

		if (i < size / 2) one_ += full_rucksack[i];
		else two_ += full_rucksack[i];

	}

	one = Compartment(one_);
	two = Compartment(two_);

	intersection_compartments();

}

Rucksack::Rucksack(std::string one, std::string two) : one (Compartment(one)), two(Compartment(two)) {

	intersection_compartments();

}

Rucksack::Rucksack(Compartment one, Compartment two) : one (one), two (two) {

	intersection_compartments();

}

Rucksack Rucksack::operator=(const Rucksack& other) {

	one = other.one;
	two = other.two;
	shared_items = other.shared_items;

	return *this;

}

void Rucksack::intersection_compartments() {

	size_t size = one.size();
	size_t i = 0;
	size_t j = 0;

	while (i < size && j < size) {

		if (one[i] == two[j]) {

			shared_items += one[i];
			i++;
			j++;

			return;

		}

		else if (one[i] < two[j]) i++;
		else j++;

	}

}

int Rucksack::get_score() {

	size_t size = shared_items.size();
	int sum = 0;

	for (size_t i = 0; i < size; i++) {

		if (shared_items[i] >= 'a' && shared_items[i] <= 'z') sum += shared_items[i] - 'a' + 1;
		else if (shared_items[i] >= 'A' && shared_items[i] <= 'Z') sum += shared_items[i] - 'A' + 1 + 26;

	}

	return sum;

}

