#include "Victim.hpp"

Victim::Victim(std::string name)
{	
	this->_name = name;
	std::cout << "Some random victim called " + this->_name + " just popped !" << std::endl;
	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " +  this->_name + " just died for no apparent reason !" << std::endl;
	return;
}

std::string const & Victim::getName(void) const
{
	return (this->_name);
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->_name + " has been turned into a cute sheep !" << std::endl;
}

std::ostream & operator<<(std::ostream & os, Victim const & tmp)
{
	os << "I am " + tmp.getName() + " and I like otters !" << std::endl;
	return (os);
}