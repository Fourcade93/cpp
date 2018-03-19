#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	this->_name = name;
	std::cout << "Zog Zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->_name + " has been turned into a pink pony !" << std::endl;
}

std::ostream & operator<<(std::ostream & os, Peon const & tmp)
{
	os << "I am " + tmp.getName() + " and I like otters !" << std::endl;
	return (os);
}
