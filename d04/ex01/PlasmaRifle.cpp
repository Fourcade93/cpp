#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
	return;
}

PlasmaRifle::~PlasmaRifle(void) { return; }

void	PlasmaRifle::attack(void) const
{
	std::cout << "*  piouuu piouuu piouuu *" << std::endl;
}
