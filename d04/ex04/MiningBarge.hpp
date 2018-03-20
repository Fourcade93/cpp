#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class MiningBarge
{
private:
	IMiningLaser *_lasers[4];
	int _count;

public:
	MiningBarge();
	~MiningBarge();

	void	equip(IMiningLaser* laser);
	void	mine(IAsteroid* ast) const;	
};

#endif
