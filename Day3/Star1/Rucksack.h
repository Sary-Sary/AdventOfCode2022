#pragma once
#include "Compartment.h"

class Rucksack
{
	Compartment one;
	Compartment two;

	

public:

	std::string shared_items;

	Rucksack();
	Rucksack(std::string full);
	Rucksack(std::string one, std::string two);
	Rucksack(Compartment one, Compartment two);

	Rucksack operator=(const Rucksack& other);

	void intersection_compartments();
	int get_score();


};

