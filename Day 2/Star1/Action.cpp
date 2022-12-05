#include "Action.h"
#include <iostream>

Action::Action() {

	action = rock;

}

Action::Action(Play action_) : action (action_) {}

Action::Action(char action_) {

	if (action_ == 'A' || action_ == 'X') action = rock;
	else if (action_ == 'B' || action_ == 'Y') action = paper;
	else if (action_ == 'C' || action_ == 'Z') action = scissors;

}

Action::~Action() {}

bool Action::operator>(const Action& other) {

	if (action > other.action && (other.action != rock || action == paper)) return 1; //paper > rock && scissors > paper
	if (action == rock && other.action == scissors) return 1; //rock > scissors
	return 0;

}

bool Action::operator==(const Action& other) {

	return action == other.action;

}

Action Action::operator= (const Action& other) {

	action = other.action;
	return *this;

}

int Action::return_score() { return action; }
