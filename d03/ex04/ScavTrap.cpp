#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	std::cout << "\033[1;32m" + this->_name + "\033[0;32m was come to our world\033[0m" << std::endl;
	this->_enPoints = 50;
	this->_maxEnPoints = 50;
	this->_meleeDamage = 20;
	this->_rangedDamage = 15;
	this->_damageReduct = 3;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[1;31m" << this->_name << "\033[0;31m was leave our world\033[0m" << std::endl;
	return;
}

void	ScavTrap::challengeNewcomer(void)
{
	std::string attacks[] = {"jump", "hit", "climb", "flip", "scream"};

	if (this->_enPoints == 0)
		std::cout << "\033[1;33m" + this->_name + "\033[0;33m doesn't have enough energy to try challange\033[0m" << std::endl;
	else
	{
		this->_enPoints -= 25;
		std::cout << "\033[0;33mSC4G-TP \033[1;33m" + this->_name + "\033[0;33m was try to \033[0;33m" + attacks[rand() % 5] + " but failed!\033[0m" << std::endl;
	}
}
