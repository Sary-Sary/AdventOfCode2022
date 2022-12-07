// AOC_2022_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include "Read_FIle.cpp"

int amount_of_inaccurate_assignments(std::vector<Assignment> assignments) {

    int amount = 0;
    size_t size = assignments.size();

    for (size_t i = 0; i < size; i++) {

        if (assignments[i].assignment_pair_fully_contains_other_assignment_pair()) amount++;

    }


    return amount;

}

int amount_of_intersection_assignments(std::vector<Assignment> assignments) {

    int amount = 0;
    size_t size = assignments.size();

    for (size_t i = 0; i < size; i++) amount += assignments[i].assignment_pairs_intersect();

    return amount;

}

int main()
{
    
    std::vector<Assignment> assignments;
    read_assignments(&assignments);

    std::cout << amount_of_intersection_assignments(assignments);

    //Assignment test(2, 6, 4, 8);
   // std::cout << test.assignment_pairs_intersect();

}

