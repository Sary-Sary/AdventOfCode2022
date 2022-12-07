#include "Assignment.h"
#include <iostream>

Assignment::Assignment() {

	elf_pair_1.first = 0;
	elf_pair_1.second = 0;

	elf_pair_2.first = 0;
	elf_pair_2.second = 0;

}

Assignment::Assignment(int section_start1, int section_end1, int section_start2, int section_end2) {

	elf_pair_1.first = section_start1;
	elf_pair_1.second = section_end1;

	elf_pair_2.first = section_start2;
	elf_pair_2.second = section_end2;

}

bool first_pair_contains_other_pair(std::pair<int, int> first_pair, std::pair <int, int> second_pair) { 

	return first_pair.first <= second_pair.first && first_pair.second >= second_pair.second;

}

bool Assignment::assignment_pair_fully_contains_other_assignment_pair() { 

	return first_pair_contains_other_pair(elf_pair_1, elf_pair_2) || first_pair_contains_other_pair(elf_pair_2, elf_pair_1);

}

bool pairs_intersect(std::pair<int, int> first_pair, std::pair <int, int> second_pair) {  

	return !(first_pair.second < second_pair.first || second_pair.second < first_pair.first);

}

bool Assignment::assignment_pairs_intersect() {

	return pairs_intersect(elf_pair_1, elf_pair_2) || pairs_intersect(elf_pair_2, elf_pair_1);
}


/*

.......... a1 a2 a3 a4 a5 a6 ......
....................a4 a5 a6 a7 a8.....

a6 > a4

....................a4 a5 a6 a7 a8.....
...........a1 a2 a3 a4 a5 a6...........

a8 > a1

*/