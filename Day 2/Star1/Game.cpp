#include "Game.h"

Game::Game() {}

Game::Game(Play player_action, Play elf_action) : player_action(Action(player_action)), elf_action(Action(elf_action)) {}

Game::Game(Action player_action, Action elf_action) : player_action (player_action), elf_action (elf_action) {}

Game::~Game() {}

Game Game::operator=(const Game& other) {

	player_action = other.player_action;
	elf_action = other.elf_action;

	return *this;

}

int Game::score() {

	if (is_win()) return player_action.return_score() + 6;
	if (is_tie()) return player_action.return_score() + 3;
	return player_action.return_score();

}

bool Game::is_win() {

	return player_action > elf_action;

}

bool Game::is_tie() {

	return player_action == elf_action;

}

bool Game::is_lose() {

	return !(player_action > elf_action) && !(player_action == elf_action);

}
 