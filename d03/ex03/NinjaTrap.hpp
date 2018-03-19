#ifndef NINHJATRAP_HPP
# define NINHJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string name);
	~NinjaTrap();
	
	void	ninjaShoebox(FragTrap const & enemy) const;
	void	ninjaShoebox(ScavTrap const & enemy) const;
	void	ninjaShoebox(NinjaTrap const & enemy) const;
};

#endif