#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	std::string letters[2] = {"bcdfghjklmnpqrstvwxyz", "aeiouy"};
	int len = rand() % 5 + 5;

	this->horde = new Zombie[N];
	this->num = N;

	for (int i = 0; i < N; ++i)
	{
		std::ostringstream ss;
		for (int i = 0; i < len; ++i)
		{
			ss << letters[i % 2][rand() % letters[i % 2].size()];
		}
		std::string name = ss.str();
		name[0] -= 32;
		horde[i].name = name;
		horde[i].type = "zonder";
	}
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->horde;
	return;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->num; ++i)
	{
		this->horde[i].announce();
	}
}
