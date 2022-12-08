#pragma once
#include <string>

class Datastream_Buffer
{
	std::string buffer;

public:

	Datastream_Buffer();
	Datastream_Buffer(std::string buffer) : buffer(buffer) {}

	char operator[](int position) const { return buffer[position]; }

	std::string get_string() const { return buffer; }
	size_t get_size() const { return buffer.size(); }

};

