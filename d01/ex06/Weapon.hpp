#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
public:
	Weapon(std::string ntype);
	~Weapon();
	
	std::string type;
	void	setType(std::string ntype);
	std::string const & getType(void);
};

#endif