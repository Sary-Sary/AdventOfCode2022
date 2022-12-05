// AOC_2022_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include "Game.h"
#include "Read_File2.cpp"

int calculate_score(std::vector <Game> games) {

    int sum = 0;
    size_t size = games.size();

    for (size_t i = 0; i < size; i++) {

        sum += games[i].score();

    }

    return sum;

}

int main()
{
    std::vector <Game> games;
    read_games2(&games);

    std::cout << calculate_score(games);

}

