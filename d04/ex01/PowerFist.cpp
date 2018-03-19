#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::~PowerFist(void) { return; }

void	PowerFist::attack(void) const
{
	std::cout << "*  pschhh... SBAM! *" << std::endl;
}
