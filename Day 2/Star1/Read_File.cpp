#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"


const std::string file_name = "input.txt";

inline void read_games(std::vector <Game>* games) {

	std::fstream file(file_name);
	
	if (!file.is_open()) {

		std::perror("Errooor");

		//error

	}

	std::string reader;
	char elf_action = 0;
	char player_action = 0;

	while (std::getline(file, reader)) {

		elf_action = reader[0];
		player_action = reader[2];

		games->push_back(Game(Action(player_action), Action(elf_action)));

	}

	file.close();

	return;

}