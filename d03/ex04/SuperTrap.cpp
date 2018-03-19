#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : FragTrap(name), NinjaTrap(name)
{
	this->_name = name;
	std::cout << "\033[0;32mSuperTrap \033[1;32m" + this->_name + "\033[0;32m come like thunder\033[0m" << std::endl;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_enPoints = 120;
	this->_maxEnPoints = 120;
	this->_meleeDamage = 60;
	this->_rangedDamage = 20;
	this->_damageReduct = 5;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "\033[0;31mSuperTrap \033[1;31m" + this->_name + "\033[0;31m leave us after good battle\033[0m" << std::endl;
	return;
}
