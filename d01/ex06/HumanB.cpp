#include "HumanB.hpp"

HumanB::HumanB(std::string nname) : name(nname)
{
	return;
}

HumanB::~HumanB(void) { return; }

void	HumanB::attack(void)
{
	std::cout << this->name + " attacks with his " + this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon & club)
{
	this->weapon = &club;
}
