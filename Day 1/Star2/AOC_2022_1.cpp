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

int three_highest_elf_calories(std::vector <Elf> elves) {

    size_t amount_of_elves = elves.size();

    if (amount_of_elves < 3) return 0;

    int highest = elves[0].get_amount_of_calories();
    int second_highest = elves[1].get_amount_of_calories();
    int third_highest = elves[2].get_amount_of_calories();

    if (second_highest < third_highest) std::swap(second_highest, third_highest);
    if (highest < second_highest) std::swap(highest, second_highest);

    for (size_t i = 3; i < amount_of_elves; i++) {

        if (elves[i].get_amount_of_calories() > highest) {

            third_highest = second_highest;
            second_highest = highest;
            highest = elves[i].get_amount_of_calories();
            
        }

        else if (elves[i].get_amount_of_calories() > second_highest) {
            third_highest = second_highest;
            second_highest = elves[i].get_amount_of_calories();
        }

        else if (elves[i].get_amount_of_calories() > third_highest) third_highest = elves[i].get_amount_of_calories();

    }

    return highest + second_highest + third_highest;

}

int main()
{
    std::vector <Elf> elves;
    read_elves(&elves);

    int highest_calorie = 0;
    highest_calorie = highest_elf_calories(elves);

    std::cout << highest_calorie << "\n";
    std::cout << three_highest_elf_calories(elves);
    
}

