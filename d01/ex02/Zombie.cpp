#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "\033[0;32mZombie is borned.\033[0m" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[0;31mZombie \033[1;31m" << this->name << "\033[0;31m is died.\033[0m" << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << "<\033[0;32m" << this->name << "\033[0m (\033[0;36m" << this->type << "\033[0m)> \033[0;33mBraiiiiiiinnnssss...\033[0m" << std::endl;
}
