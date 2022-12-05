#pragma once
#include "Action.h"
#include <iostream>

class Game
{
	Action player_action;
	Action elf_action;

public:

	Game();
	Game(Play player_action, Play elf_action);
	Game(Action player_action, Action elf_action);
	~Game();

	Game operator=(const Game& other);

	bool is_win();
	bool is_tie();
	bool is_lose();
	int score();

};

