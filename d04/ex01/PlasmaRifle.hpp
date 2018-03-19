#ifndef PLASMA_HPP
# define PLASMA_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	~PlasmaRifle();
	
	void attack() const;
};

#endif
