#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _name(name), _hitPoints(100), _maxHitPoints(100), _enPoints(50), _maxEnPoints(50), _level(1), _meleeDamage(20), _rangedDamage(15), _damageReduct(3)
{
	std::cout << "\033[1;32m" + this->_name + "\033[0;32m was come to our world\033[0m" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[1;31m" << this->_name << "\033[0;31m was leave our world\033[0m" << std::endl;
	return;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "\033[0;33mSC4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m at range, causing " << this->_rangedDamage << " points of damage !\033[0m" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "\033[0;33mSC4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m at melee, causing " << this->_maleeDamage << " points of damage !\033[0m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	int damage;

	if (this->_hitPoints == 0)
		std::cout << "\033[1;35m" + this->_name + "\033[0;35m can't get damage anymore\033[0m" << std::endl;
	else
	{
		damage = this->_hitPoints;
		if (this->_damageReduct < (int)amount && 
			(this->_hitPoints += this->_damageReduct - (int)amount) < 0)
			this->_hitPoints = 0;
		std::cout << "\033[1;35m" + this->_name + "\033[0;35m has got " << damage - this->_hitPoints << " points of damage\033[0m" << std::endl;
	}
}
void	ScavTrap::beRepaired(unsigned int amount)
{
	int health;

	if (this->_hitPoints == 100)
		std::cout << "\033[1;36m" + this->_name + "\033[0;36m completely as new\033[0m" << std::endl;
	else
	{
		health = this->_hitPoints;
		if ((this->_hitPoints += (int)amount) > 100)
			this->_hitPoints = 100;
		std::cout << "\033[1;36m" + this->_name + "\033[0;36m has got " << this->_hitPoints - health << " points of health\033[0m" << std::endl;
	}
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
