#pragma once
#include <string>

class Compartment
{
	std::string items;

public:

	Compartment();
	Compartment(std::string itmes);
	~Compartment();

	Compartment operator=(const Compartment& other);
	char operator[](int position);
	std::string operator/(const Compartment& other);

	void sort_items();

	size_t size();

};

