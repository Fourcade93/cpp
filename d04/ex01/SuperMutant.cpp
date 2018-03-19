#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}

void SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage > 0)
		this->setHP((this->getHP() < damage) ? 0 : this->getHP() - damage);
}
