#pragma once
#include <vector>


class Elf
{
	std::vector<int> calories;
	int amount_of_calories;

public:

	Elf();
	Elf(std::vector<int> calories);

	~Elf();

	int get_amount_of_calories();

	Elf operator=(const Elf& other);

};

