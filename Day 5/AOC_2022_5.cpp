// AOC_2022_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Cargo.h"
#include <string>

const std::string file_name = "input.txt";

void read_file(std::vector<Move>* moves) {

    std::fstream file(file_name);

    if (!file.is_open()) {

        std::perror("Error");

    }

    std::string reader;
    std::stringstream stream;
    std::string buff;

    int move;
    int from;
    int to;


    while (std::getline(file, reader)) {

        stream << reader;
        stream >> buff >> move >> buff >> from >> buff >> to;

        moves->push_back(Move(move, from, to));

        stream.clear();

    }

    return;

}

void apply_moves_to_cargo(Cargo* cargo, std::vector<Move> moves) {

    size_t amount_of_moves = moves.size();

    for (size_t i = 0; i < amount_of_moves; i++) {

        cargo->move(moves[i]);

    }

    return;

}

void apply_moves_9001_to_cargo(Cargo* cargo, std::vector<Move> moves) {

    size_t amount_of_moves = moves.size();

    for (size_t i = 0; i < amount_of_moves; i++) {

        cargo->move_9001(moves[i]);

    }

    return;

}

int main()
{
    
    Cargo cargo;

    cargo.push('T', 1);
    cargo.push('D', 1);
    cargo.push('W', 1);
    cargo.push('Z', 1);
    cargo.push('V', 1);
    cargo.push('P', 1);

    cargo.push('L', 2);
    cargo.push('S', 2);
    cargo.push('W', 2);
    cargo.push('V', 2);
    cargo.push('F', 2);
    cargo.push('J', 2);
    cargo.push('D', 2);

    cargo.push('Z', 3);
    cargo.push('M', 3);
    cargo.push('L', 3);
    cargo.push('S', 3);
    cargo.push('V', 3);
    cargo.push('T', 3);
    cargo.push('B', 3);
    cargo.push('H', 3);

    cargo.push('R', 4);
    cargo.push('S', 4);
    cargo.push('J', 4);

    cargo.push('C', 5);
    cargo.push('Z', 5);
    cargo.push('B', 5);
    cargo.push('G', 5);
    cargo.push('F', 5);
    cargo.push('M', 5);
    cargo.push('L', 5);
    cargo.push('W', 5);

    cargo.push('Q', 6);
    cargo.push('W', 6);
    cargo.push('V', 6);
    cargo.push('H', 6);
    cargo.push('Z', 6);
    cargo.push('R', 6);
    cargo.push('G', 6);
    cargo.push('B', 6);

    cargo.push('V', 7);
    cargo.push('J', 7);
    cargo.push('P', 7);
    cargo.push('C', 7);
    cargo.push('B', 7);
    cargo.push('D', 7);
    cargo.push('N', 7);

    cargo.push('P', 8);
    cargo.push('T', 8);
    cargo.push('B', 8);
    cargo.push('Q', 8);

    cargo.push('H', 9);
    cargo.push('G', 9);
    cargo.push('Z', 9);
    cargo.push('R', 9);
    cargo.push('C', 9);

    std::vector<Move> moves;
    read_file(&moves);

    apply_moves_9001_to_cargo(&cargo, moves);
    cargo.read_top_cargo();

}

/*
        [H]     [W] [B]
    [D] [B]     [L] [G] [N]
[P] [J] [T]     [M] [R] [D]
[V] [F] [V]     [F] [Z] [B]     [C]
[Z] [V] [S]     [G] [H] [C] [Q] [R]
[W] [W] [L] [J] [B] [V] [P] [B] [Z]
[D] [S] [M] [S] [Z] [W] [J] [T] [G]
[T] [L] [Z] [R] [C] [Q] [V] [P] [H]
 1   2   3   4   5   6   7   8   9
*/