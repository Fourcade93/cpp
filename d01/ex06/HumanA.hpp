#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string nname, Weapon & club);
	~HumanA();
	
	Weapon & weapon;
	std::string name;

	void	attack(void);
};

#endif