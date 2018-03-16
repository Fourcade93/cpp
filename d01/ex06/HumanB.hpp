#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string nname);
	~HumanB();
	
	Weapon * weapon;
	std::string name;

	void	setWeapon(Weapon & club);
	void	attack(void);
};

#endif