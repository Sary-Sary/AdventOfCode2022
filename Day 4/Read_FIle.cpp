#include <fstream>
#include "Assignment.h"
#include <string>
#include <iostream>
#include <vector>

const std::string file_name = "input.txt";

inline void parse_number(size_t& i, const std::string assignment, int& number_to_parse, char stopper, const size_t& size) {

	std::string number;


	while (assignment[i] != stopper && i < size) {

		number += assignment[i];
		i++;

	}

	i++;

	number_to_parse = std::stoi(number);

	return;

}

inline void parse_to_sections(int& section_start1, int& section_end1, int& section_start2, int& section_end2, std::string assignment) {

	int size = assignment.size();
	size_t i = 0;

	parse_number(i, assignment, section_start1, '-', size);
	parse_number(i, assignment, section_end1, ',', size);
	parse_number(i, assignment, section_start2, '-', size);
	parse_number(i, assignment, section_end2, '\n', size);

	return;

}

inline void read_assignments(std::vector<Assignment>* assignments) {

	std::fstream file(file_name);

	if (!file.is_open()) {

		std::perror("Error");

	}

	std::string reader;
	int section_start1 = 0;
	int section_end1 = 0;
	int section_start2 = 0;
	int section_end2 = 0;

	while (std::getline(file, reader)) {

		parse_to_sections(section_start1, section_end1, section_start2, section_end2, reader);

		assignments->push_back(Assignment(section_start1, section_end1, section_start2, section_end2));

	}


}