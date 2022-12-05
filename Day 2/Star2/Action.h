#pragma once
#include <string>

enum Play {

	rock = 1,
	paper = 2,
	scissors = 3

};

const int win = 1;
const int tie = 2;
const int lose = 3;

class Action
{
	
	Play action;


public:

	Action();
	Action(Play action);
	Action(char action);
	Action(char action, int condition);
	~Action();

	int return_score();
	Play get_play();

	bool operator>(const Action& other);
	bool operator==(const Action& other);

	Action operator=(const Action& other);

};

