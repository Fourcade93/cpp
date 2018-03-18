#include "FragTrap.hpp"

int main(void)
{
	std::srand(std::time(0));
	FragTrap bob("Bob");
	FragTrap jim("Jim");

	bob.rangedAttack("Jim");
	jim.takeDamage(20);

	jim.vaulthunter_dot_exe("Bob");
	jim.vaulthunter_dot_exe("Bob");
	jim.vaulthunter_dot_exe("Bob");
	jim.vaulthunter_dot_exe("Bob");
	jim.vaulthunter_dot_exe("Bob");

	bob.takeDamage(200);

	jim.beRepaired(100);
	jim.meleeAttack("Bob");
	bob.takeDamage(30);
	return 0;
}
