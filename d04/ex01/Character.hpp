#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string _name;
	int _ap;
	AWeapon *_weapon;
public:
	Character(std::string const & name);
	~Character();
	
	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(Enemy*);
	AWeapon const * getWeapon() const;
	int getAP() const;
	std::string const & getName() const;
};

std::ostream & operator<<(std::ostream & os, Character const & tmp);

#endif