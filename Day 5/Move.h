#pragma once
struct Move
{
	int amount;
	int from;
	int to;

public:

	Move(int amount, int from, int to) : amount (amount), from(from), to(to) {}

};

