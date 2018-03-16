#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) { return; }
ZombieEvent::~ZombieEvent(void) { return; }

void	ZombieEvent::setZombieType(std::string new_type)
{
	this->_type = new_type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie* ret = new Zombie;
	ret->type = this->_type;
	ret->name = name;
	return (ret);
}

void	ZombieEvent::randomChump(void)
{
	std::string letters[2] = {"bcdfghjklmnpqrstvwxyz", "aeiouy"};
	int len = rand() % 5 + 5;
	std::ostringstream ss;

	for (int i = 0; i < len; ++i)
	{
		ss << letters[i % 2][rand() % letters[i % 2].size()];
	}
	std::string name = ss.str();
	name[0] -= 32;
	Zombie* tmp = this->newZombie(name);
	tmp->announce();
	delete tmp;
}
