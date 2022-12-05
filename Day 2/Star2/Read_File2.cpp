#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"


const std::string file_name = "input.txt";


inline void read_games2(std::vector <Game>* games) {

	std::fstream file(file_name);

	if (!file.is_open()) {

		std::perror("Errooor");

		//error

	}

	std::string reader;
	char elf_action = 0;
	int win_tie_lose = 0; 

	while (std::getline(file, reader)) {

		elf_action = reader[0];
		
		if (reader[2] == 'X') win_tie_lose = lose;
		if (reader[2] == 'Y') win_tie_lose = tie;
		if (reader[2] == 'Z') win_tie_lose = win;

		games->push_back(Game(Action(elf_action, win_tie_lose), Action(elf_action)));

	}

	file.close();

	return;

}