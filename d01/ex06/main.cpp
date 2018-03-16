#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("paradise club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB bob("Bob");

		bob.setWeapon(club);
		bob.attack();
		club.setType("paradise club");
		bob.attack();
		return 0;
	}
}
	