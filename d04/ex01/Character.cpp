#include "Character.hpp"

Character::Character(std::string const & name)
{
	this->_name = name;
	this->_weapon = NULL;
	this->_ap = 40;
	return;
}

Character::~Character(void) { return; }

void	Character::equip(AWeapon * weapon)
{
	this->_weapon = weapon;
}

void	Character::attack(Enemy * enemy)
{
	if (this->_weapon && this->_ap >= this->_weapon->getAPCost())
	{
		std::cout << this->_name + " attacks " + enemy->getType() + " with a " +
		this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		this->_ap -= this->_weapon->getAPCost();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

AWeapon const * Character::getWeapon(void) const
{
	return (this->_weapon);
}

std::string const & Character::getName(void) const
{
	return (this->_name);
}

int Character::getAP(void) const
{
	return (this->_ap);
}

void Character::recoverAP(void)
{
	if (this->_ap <= 30)
		this->_ap += 10;
}

std::ostream & operator<<(std::ostream & os, Character const & tmp)
{
	if (tmp.getWeapon())
		os << tmp.getName() + " has " << tmp.getAP() << " AP and wields a " + tmp.getWeapon()->getName() << std::endl;
	else
		os << tmp.getName() + " has " << tmp.getAP() << " AP and is unarmed" << std::endl;
	return (os);
}
