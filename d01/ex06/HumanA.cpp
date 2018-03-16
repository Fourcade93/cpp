#include "HumanA.hpp"

HumanA::HumanA(std::string nname, Weapon & club) : name(nname), weapon(club)
{
	return;
}

HumanA::~HumanA(void) { return; }

void	HumanA::attack(void)
{
	std::cout << this->name + " attacks with his " + this->weapon.getType() << std::endl;
}
