#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->_name = name;
	this->_apcost = apcost;
	this->_damage = damage;
	return;
}

AWeapon::~AWeapon(void) { return; }

int AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}

std::string const & AWeapon::getName(void) const
{
	return (this->_name);
}

int AWeapon::getDamage(void) const
{
	return (this->_damage);
}
