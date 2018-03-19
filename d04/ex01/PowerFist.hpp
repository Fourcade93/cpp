#ifndef POWER_HPP
# define POWER_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	~PowerFist();
	
	void attack() const;
};

#endif
