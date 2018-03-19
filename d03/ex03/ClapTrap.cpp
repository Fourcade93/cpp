#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(100), _maxHitPoints(100), _level(1)
{
	std::cout << "ClapTrap is ready for battle" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap was destroy" << std::endl;
	return;
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "\033[0;33mSC4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m at range, causing " << this->_rangedDamage << " points of damage !\033[0m" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "\033[0;33mSC4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m at melee, causing " << this->_meleeDamage << " points of damage !\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
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
void	ClapTrap::beRepaired(unsigned int amount)
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

std::string const & ClapTrap::getName(void) const
{
	return (this->_name);
}
