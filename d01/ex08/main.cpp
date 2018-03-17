#include "Human.hpp"

int main(void)
{
	Human	bob("Bob");

	bob.action("meleeAttack", "orks");
	bob.action("rangeAttack", "orks");
	bob.action("intimidatingShout", "orks");
	bob.action("bla-bla", "orks");
	return 0;
}
