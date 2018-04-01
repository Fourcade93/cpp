#include "easyfind.hpp"
#include <list>

int main(void)
{
	std::list <int> lst;

	lst.push_back(21);
	lst.push_back(42);
	lst.push_back(84);

	easyfind(lst, 42);
	try
	{
		easyfind(lst, 10);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
