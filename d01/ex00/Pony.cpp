#include "Pony.hpp"

Pony::Pony(void)
{
	std::cout << "Please enter pony name: \033[0;36m";
	getline(std::cin, this->name);
	std::cout << "\033[0mPlease enter pony color: \033[0;36m";
	getline(std::cin, this->color);
	std::cout << "\033[0mPlease enter pony age: \033[0;36m";
	std::cin >> age;
	while (std::cin.fail())
	{
		std::cout << "\033[0mError. Please enter a nunmber.\033[0;36m" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> age;
	}
	std::cin.ignore(256, '\n');
	std::cout << "\033[0;32mPony with name \033[1;32m" << this->name << "\033[0;32m borned.\033[0m" << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << "\033[0;31mPony with name \033[1;31m" << this->name << "\033[0;31m died\033[0m." << std::endl;
	return;	
}
