#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* kate = new TacticalMarine;
	ISpaceMarine* jane = new AssaultTerminator;

	ISquad* vlc = new Squad;
	Squad* vlc2 = new Squad;

	vlc->push(bob);
	vlc->push(jim);
	vlc2->push(kate);
	vlc2->push(jane);
	*vlc2 = *vlc;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	delete vlc2;
	return 0;
}