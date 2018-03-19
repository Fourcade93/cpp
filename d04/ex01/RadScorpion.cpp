#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

void RadScorpion::takeDamage(int damage)
{
	if (damage > 0)
		this->setHP((this->getHP() < damage) ? 0 : this->getHP() - damage);
}
