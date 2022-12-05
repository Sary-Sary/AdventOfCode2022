#pragma once
#include <string>

enum Play {

	rock = 1,
	paper = 2,
	scissors = 3

};

class Action
{
	
	Play action;


public:

	Action();
	Action(Play action);
	Action(char action);
	~Action();

	int return_score();

	bool operator>(const Action& other);
	bool operator==(const Action& other);

	Action operator=(const Action& other);

};

