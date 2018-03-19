#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(std::string name);
	~SuperTrap();
	
};

#endif
