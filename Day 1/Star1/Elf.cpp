#include "Elf.h"

Elf::Elf() {

	amount_of_calories = 0;

}

Elf::Elf(std::vector<int> calories_) : calories(calories_) {

	amount_of_calories = 0;

	size_t size = calories.size();

	for (size_t i = 0; i < size; i++) {

		amount_of_calories += calories[i];

	}


}

Elf::~Elf() {}

int Elf::get_amount_of_calories() { return amount_of_calories; }

Elf Elf::operator=(const Elf& other) {

	calories = other.calories;
	amount_of_calories = other.amount_of_calories;

	return *this;

}
