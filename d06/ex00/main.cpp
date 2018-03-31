#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <errno.h>

void	print_char(char *str)
{
	char c;

	c = static_cast<char>(std::atoi(str));
	if (errno)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
}

void	print_int(char *str)
{
	int c;

	c = static_cast<int>(std::atoi(str));
	if (errno)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << c << std::endl;
}

void	print_float(char *str)
{
	float c;

	c = static_cast<float>(std::atof(str));
	std::cout << "float: " << c << "f" << std::endl;
}

void	print_double(char *str)
{
	double c;

	c = static_cast<double>(std::strtod(str, NULL));
	std::cout << "double: " << c << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		exit(-1);
	print_char(argv[1]);
	print_int(argv[1]);
	std::cout << std::fixed;
	std::cout.precision(1);
	print_float(argv[1]);
	print_double(argv[1]);
	return 0;
}