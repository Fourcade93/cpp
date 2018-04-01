#include "Array.hpp"

#include <iostream>

int main(void)
{
	Array<int> a(5);
	Array<int> b(a);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "\033[0;36ma[" << i << "] = \033[0m";
		std::cout.width(14);
		std::cout << a[i];
		std::cout <<  "\033[0;36m, b[" << i << "] = \033[0m";
		std::cout.width(14);
		std::cout << b[i] << std::endl;
	}

	a[1] = 256;
	std::cout << "\033[0;36ma[" << 1 << "] = \033[0m";
	std::cout.width(14);
	std::cout << a[1] << std::endl;
	std::cout << "\033[0;36mb[" << 1 << "] = \033[0m";
	std::cout.width(14);
	std::cout << b[1] << std::endl;

	b[1] = 512;
	std::cout << "\033[0;36mb[" << 1 << "] = \033[0m";
	std::cout.width(14);
	std::cout << b[1] << std::endl;

	try
	{
		std::cout << b[6] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "\033[0;31mCan't get element because " << e.what() << "\033[0m" << std::endl;
	}
	return 0;
}
