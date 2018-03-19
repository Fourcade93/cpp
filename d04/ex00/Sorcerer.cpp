#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name + ", " + this->_title + " is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name + ", " + this->_title + " is dead. Consequences will never be the same !" << std::endl;
	return;
}

std::string const & Sorcerer::getName(void) const
{
	return (this->_name);
}

std::string const & Sorcerer::getTitle(void) const
{
	return (this->_title);
}

void	Sorcerer::polymorph(Victim const & tmp) const
{
	tmp.getPolymorphed();
}

std::ostream & operator<<(std::ostream & os, Sorcerer const & tmp)
{
	os << "I am " + tmp.getName() + ", " + tmp.getTitle() + ", and I like ponies !" << std::endl;
	return (os);
}
