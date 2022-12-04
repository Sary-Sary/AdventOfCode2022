// AOC_2022_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Read_file.cpp"



int highest_elf_calories(std::vector <Elf> elves) {

    size_t amount_of_elves = elves.size();
    int current_highest = elves[0].get_amount_of_calories();

    for (size_t i = 1; i < amount_of_elves; i++) {

        if (current_highest < elves[i].get_amount_of_calories()) current_highest = elves[i].get_amount_of_calories();

    }

    return current_highest;

}

int main()
{
    std::vector <Elf> elves;
    read_elves(&elves);

    int highest_calorie = 0;
    highest_calorie = highest_elf_calories(elves);

    std::cout << highest_calorie;
}

