#include "Weapon.hpp"

Weapon::Weapon(std::string ntype) : type(ntype) { return; }
Weapon::~Weapon(void) { return; }

void	Weapon::setType(std::string ntype)
{
	this->type = ntype;
}

std::string const & Weapon::getType(void)
{
	return (this->type);
}
