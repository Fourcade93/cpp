#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") { return; }
Ice::Ice(AMateria const & src) : AMateria(src) { return; }

Ice::~Ice(void) { return; }

AMateria* Ice::clone(void) const
{
	return (new Ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() << std::endl;
	this->increaseXP();
}
