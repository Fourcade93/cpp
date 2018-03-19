#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer();

	std::string const & getName(void) const;
	std::string const & getTitle(void) const;
	void	polymorphed(Victim const & tmp) cons

protected:
	std::string _name;
	std::string _title;
	
};

std::ostream & operator<<(std::ostream & os, Sorcerer const & tmp);

#endif
