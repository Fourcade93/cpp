#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	this->xp_ = 0;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int AMateria::getXP(void) const
{
	return (this->xp_);
}

void	AMateria::increaseXP(void)
{
	this->xp_ += 10;
}

AMateria & AMateria::operator=(AMateria const & src)
{
	this->xp_ = src.getXP();
	this->_type = src.getType();
	return (*this);
}
