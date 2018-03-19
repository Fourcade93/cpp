#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : _name(name), _hitPoints(100), _maxHitPoints(100), _enPoints(100), _maxEnPoints(100), _level(1), _meleeDamage(30), _rangedDamage(20), _damageReduct(5)
{
	std::cout << "\033[0;32mRobot \033[1;32m" << this->_name << "\033[0;32m was born\033[0m" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "\033[0;31mRobot \033[1;31m" << this->_name << "\033[0;31m was die\033[0m" << std::endl;
	return;
}

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "\033[0;33mFR4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m at range, causing " << this->_rangedDamage << " points of damage !\033[0m" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "\033[0;33mFR4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m at melee, causing " << this->_maleeDamage << " points of damage !\033[0m" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
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
void	FragTrap::beRepaired(unsigned int amount)
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

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[] = {"Splash Attack", "Bomb", "Hammerblow", "Fist of fury", "Crushing"};

	if (this->_enPoints == 0)
		std::cout << "\033[1;33m" + this->_name + "\033[0;33m doesn't have enough energy to attack\033[0m" << std::endl;
	else
	{
		this->_enPoints -= 25;
		std::cout << "\033[0;33mFR4G-TP \033[1;33m" + this->_name + "\033[0;33m attacks \033[1;33m" + target + "\033[0;33m with " + attacks[rand() % 5] + " !\033[0m" << std::endl;
	}
}
