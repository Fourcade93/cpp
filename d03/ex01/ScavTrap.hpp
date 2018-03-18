#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(void);
private:
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
