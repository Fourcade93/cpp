#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") { return; }
Cure::Cure(AMateria const & src) : AMateria(src) { return; }

Cure::~Cure(void) { return; }

AMateria* Cure::clone(void) const
{
	return (new Cure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;;
	this->increaseXP();
}
