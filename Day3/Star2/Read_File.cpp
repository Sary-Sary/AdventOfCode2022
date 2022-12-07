#include <vector>
#include <fstream>
#include <iostream>
#include "Elf_Group.h"

const std::string file_name = "input.txt";

inline void read_rucksacks(std::vector <Elf_Group>* elves) {

	std::fstream file(file_name);

	if (!file.is_open()) {

		std::perror("Error.");

	}

	std::string reader;
	std::string first_elf;
	std::string second_elf;
	std::string third_elf;
	int counter = 0;

	while (std::getline(file, reader)) {

		counter++;

		if (counter % 3 == 0) {

			third_elf = reader;
			elves->push_back(Elf_Group(first_elf, second_elf, third_elf));

			first_elf.clear();
			second_elf.clear();
			third_elf.clear();

		}

		if (counter % 2 == 0) second_elf = reader;
		else first_elf = reader;


	}

	file.close();

	return;

}
