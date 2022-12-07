#pragma once
#include "Compartment.h"

class Elf_Group 
{
	Compartment one;
	Compartment two;
	Compartment three;

	

public:

	std::string shared_items;

	Elf_Group();
	//Rucksack(std::string full);
	Elf_Group(std::string one, std::string two, std::string three);
	Elf_Group(Compartment one, Compartment two, Compartment three);

	Elf_Group operator=(const Elf_Group& other);

	std::string intersection_compartments();
	int get_score();


};

