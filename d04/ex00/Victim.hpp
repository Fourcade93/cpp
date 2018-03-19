#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
public:
	Victim(std::string name);
	~Victim();
	
	std::string const & getName(void) const;
	virtual void	getPolymorphed(void) const;

protected:
	std::string _name;
};

std::ostream & operator<<(std::ostream & os, Victim const & tmp);

#endif
