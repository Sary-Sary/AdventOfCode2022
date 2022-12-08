#pragma once
#include <stack>
#include <vector>
#include "Move.h"

class Cargo
{

	std::vector <std::stack<char>> cargo;

public:

	void move(Move move);
	void move_9001(Move move);

	void push(char chara, int stack);
	void read_top_cargo();

};

