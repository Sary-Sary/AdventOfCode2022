#include "Cargo.h"
#include <iostream>

void Cargo::move(Move move) {

	char temp = 'a';

	while (move.amount) {

		temp = cargo[move.from - 1].top();

		cargo[move.from - 1].pop();
		cargo[move.to - 1].push(temp);

		move.amount--;

	}

	return;

}

void Cargo::move_9001(Move move) {

	char temp = 'a';
	std::stack<char> rearranger;

	while (move.amount) {

		temp = cargo[move.from - 1].top();
		cargo[move.from - 1].pop();

		rearranger.push(temp);

		move.amount--;

	}

	while (rearranger.size() != 0) {

		cargo[move.to - 1].push(rearranger.top());
		rearranger.pop();

	}

	return;

}

void Cargo::push(char chara, int stack) {

	while (stack > cargo.size()) cargo.push_back({});

	cargo[stack - 1].push(chara);
	return;

}

void Cargo::read_top_cargo() {

	size_t amount_of_stack = cargo.size();

	for (size_t i = 0; i < amount_of_stack; i++) std::cout << cargo[i].top();

}
