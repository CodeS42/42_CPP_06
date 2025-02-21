#include "../headers/ScalarConverter.hpp"
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid numbers of arguments." << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	
	return (0);
}
