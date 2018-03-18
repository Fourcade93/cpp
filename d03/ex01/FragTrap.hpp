#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

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
