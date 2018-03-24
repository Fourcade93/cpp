#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat jim("Jim", 150);
	Bureaucrat bob("Bob", 1);

	std::cout << jim;
	std::cout << bob;
	try
	{
		Bureaucrat low("Low", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat high("High", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		jim -= 10;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		bob += 10;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}