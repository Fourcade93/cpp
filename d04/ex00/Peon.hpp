#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name);
	~Peon();

	void	getPolymorphed(void) const;
	
};

std::ostream & operator<<(std::ostream & os, Peon const & tmp);

#endif
