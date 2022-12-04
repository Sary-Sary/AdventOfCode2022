//#include <vector>s
#include <string>
#include <fstream>
#include "Elf.h"


const std::string file_name = "input.txt";

inline void read_elves(std::vector <Elf>* elves) {

	std::fstream file(file_name);

	if (!file.is_open()) {

		std::perror("Errooor");

		//error

	}

	std::string reader;
	int calorie;
	std::vector <int> calorie_count;
	//std::vector<Elf> elves;

	while (std::getline(file, reader)) {

		if (reader.size() == 0) {

			elves->push_back(Elf(calorie_count));
			calorie_count.clear();

		}

		else {

			calorie = std::stoi(reader);
			calorie_count.push_back(calorie);

		}

	}

	file.close();

	return;

}