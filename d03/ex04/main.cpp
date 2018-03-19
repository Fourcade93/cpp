#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"


int main(void)
{
	std::srand(std::time(0));
	FragTrap bob("Bob");
	FragTrap jim("Jim");
	ScavTrap ed("Ed");
	ScavTrap john("John");
	NinjaTrap yoko("Yoko");
	NinjaTrap spaun("Spaun");
	SuperTrap storm("Storm");

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

	ed.takeDamage(120);
	john.challengeNewcomer();
	john.challengeNewcomer();
	john.challengeNewcomer();

	jim.rangedAttack("John");
	john.takeDamage(20);

	jim.beRepaired(100);

	john.meleeAttack("bob");
	bob.takeDamage(20);
	yoko.ninjaShoebox(spaun);
	yoko.ninjaShoebox(ed);
	yoko.ninjaShoebox(jim);

	jim.meleeAttack("spaun");
	spaun.takeDamage(30);
	ed.meleeAttack("spaun");
	spaun.takeDamage(20);
	yoko.meleeAttack("spaun");
	spaun.takeDamage(60);

	storm.meleeAttack("Yoko");
	yoko.takeDamage(60);
	storm.rangedAttack("Yoko");
	yoko.takeDamage(20);
	return 0;
}
