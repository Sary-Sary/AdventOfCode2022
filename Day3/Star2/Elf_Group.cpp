#include "Rucksack.h"

Elf_Group::Elf_Group() {}

Elf_Group::Elf_Group(std::string one, std::string two, std::string three) : one (Compartment(one)), two(Compartment(two)), three (Compartment(three)) {

	shared_items = intersection_compartments();

}

Elf_Group::Elf_Group(Compartment one, Compartment two, Compartment three) : one (one), two (two), three (three) {

	shared_items = intersection_compartments();

}

Elf_Group Elf_Group::operator=(const Elf_Group& other) {

	one = other.one;
	two = other.two;
	three = other.three;
	shared_items = other.shared_items;

	return *this;

}

std::string Elf_Group::intersection_compartments() {

	std::string shared_one_two = one / two;
	std::string shared_two_three = two / three;

	Compartment shared_compartment_one_two(shared_one_two);
	Compartment shared_compartment_two_three(shared_two_three);

	return shared_compartment_one_two / shared_compartment_two_three;

}

int Elf_Group::get_score() {

	size_t size = shared_items.size();
	int sum = 0;

	for (size_t i = 0; i < size; i++) {

		if (shared_items[i] >= 'a' && shared_items[i] <= 'z') sum += shared_items[i] - 'a' + 1;
		else if (shared_items[i] >= 'A' && shared_items[i] <= 'Z') sum += shared_items[i] - 'A' + 1 + 26;

		return sum;

	}

	return sum;

}

