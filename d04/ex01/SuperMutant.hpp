#ifndef MUTANT_HPP
# define MUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	~SuperMutant();

	void	takeDamage(int damage);
	
};

#endif