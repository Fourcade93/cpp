#include "ZombieEvent.hpp"

int main(void)
{
	std::srand(std::time(0));
	ZombieEvent eventer;
	eventer.setZombieType("death smile");
	Zombie Hazel;
	Zombie* cyberHead = eventer.newZombie("cyberHead");

	Hazel.name = "Hazel";
	Hazel.type = "hell apples";
	Hazel.announce();
	cyberHead->announce();
	eventer.randomChump();
	delete cyberHead;
	return 0;
}