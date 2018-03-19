#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name)
{
	this->_name = name;
	std::cout << "\033[0;32mNinja \033[1;32m" << this->_name << "\033[0;32m is waiting for battle \033[0m" << std::endl;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_enPoints = 120;
	this->_maxEnPoints = 120;
	this->_meleeDamage = 60;
	this->_rangedDamage = 5;
	this->_damageReduct = 0;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "\033[0;31mNinja \033[1;31m" << this->_name << "\033[0;31m was crushed\033[0m" << std::endl;
	return;
}

void	NinjaTrap::ninjaShoebox(FragTrap const & enemy) const
{
	std::cout << "\033[0;33mNinja \033[1;33m" + this->_name + "\033[0;33m strikes at \033[1;33m" + enemy.getName() + "\033[0m" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & enemy) const
{
	std::cout << "\033[0;33mNinja \033[1;33m" + this->_name + "\033[0;33m hit \033[1;33m" + enemy.getName() + "\033[0m" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & enemy) const
{
	std::cout << "\033[0;33mNinja \033[1;33m" + this->_name + "\033[0;33m strikes jumping at \033[1;33m" + enemy.getName() + "\033[0m" << std::endl;
}
