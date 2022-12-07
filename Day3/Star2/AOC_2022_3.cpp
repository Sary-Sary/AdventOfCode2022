// AOC_2022_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include "Read_File.cpp"
//#include "Rucksack.h"

int properties_sum(std::vector <Elf_Group> rucksacks) {

    int sum = 0;
    size_t amount_of_rucksacks = rucksacks.size();

    for (int i = 0; i < amount_of_rucksacks; i++) {

        sum += rucksacks[i].get_score();

    } 

    return sum;

}

int main()
{
    std::vector <Elf_Group> elves;
    read_rucksacks(&elves);

    std::cout << properties_sum(elves);

}


