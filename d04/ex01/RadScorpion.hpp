#ifndef SCORPION_HPP
# define SCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	~RadScorpion();

	void	takeDamage(int damage);
	
};

#endif