#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::srand(std::time(0));
	FragTrap bob("Bob");
	FragTrap jim("Jim");
	ScavTrap ed("Ed");
	ScavTrap john("John");

	bob.rangedAttack("John");
	john.takeDamage(20);
	ed.meleeAttack("Bob");
	bob.takeDamage(20);
	ed.meleeAttack("Jim");
	jim.takeDamage(20);

	jim.vaulthunter_dot_exe("ed");
	jim.vaulthunter_dot_exe("ed");
	jim.vaulthunter_dot_exe("ed");
	jim.vaulthunter_dot_exe("ed");
	jim.vaulthunter_dot_exe("ed");

	john.challengeNewcomer();
	john.challengeNewcomer();
	john.challengeNewcomer();

	jim.rangedAttack("John");
	john.takeDamage(20);

	jim.beRepaired(100);

	john.meleeAttack("20");
	bob.takeDamage(20);
	return 0;
}
