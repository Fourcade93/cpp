#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	std::cout << "\033[0;32mRobot \033[1;32m" << this->_name << "\033[0;32m was born\033[0m" << std::endl;
	this->_enPoints = 100;
	this->_maxEnPoints = 100;
	this->_meleeDamage = 30;
	this->_rangedDamage = 20;
	this->_damageReduct = 5;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "\033[0;31mRobot \033[1;31m" << this->_name << "\033[0;31m was die\033[0m" << std::endl;
	return;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[] = {"Splash Attack", "Bomb", "Hammerblow", "Fist of fury", "Crushing"};

	if (this->_enPoints == 0)
		std::cout << "\033[1;33m" + this->_name + "\033[0;33m doesn't have enough energy to attack\033[0m" << std::endl;
	else
	{
		this->_enPoints -= 25;
		std::cout << "\033[0;33mFG4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m with " + attacks[rand() % 5] + " !\033[0m" << std::endl;
	}
}
