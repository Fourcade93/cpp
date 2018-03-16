#include "ZombieHorde.hpp"

int main(void)
{
	int num;

	std::srand(std::time(0));
	std::cout << "Please enter number: ";
	std::cin >> num;
	while (std::cin.fail())
	{
		std::cout << "Error of input. Enter number: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> num;
	}
	std::cin.ignore(256, '\n');

	ZombieHorde test(num);

	test.announce();
	return 0;
}
