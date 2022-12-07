#include <vector>
#include <fstream>
#include <iostream>
#include "Rucksack.h"

const std::string file_name = "input.txt";

inline void read_rucksacks(std::vector <Rucksack>* rucksacks) {

	std::fstream file(file_name);

	if (!file.is_open()) {

		std::perror("Error.");

	}

	std::string reader;

	while (std::getline(file, reader)) {

		rucksacks->push_back(Rucksack(reader));

	}

	file.close();

	return;

}