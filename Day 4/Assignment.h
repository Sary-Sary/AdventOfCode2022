#pragma once
#include <utility>

class Assignment
{
	std::pair <int, int> elf_pair_1;
	std::pair <int, int> elf_pair_2;

public:

	Assignment();
	Assignment(int section_start1, int section_end1, int section_start2, int section_end2);

	bool assignment_pair_fully_contains_other_assignment_pair();
	bool assignment_pairs_intersect();

};

