#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


# include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	~ClapTrap();

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
protected:
	std::string _name;
	int _hitPoints;
	int _maxHitPoints;
	int _enPoints;
	int _maxEnPoints;
	int _level;
	int _meleeDamage;
	int _rangedDamage;
	int _damageReduct;
};

#endif