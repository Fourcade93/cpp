#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner();
	~DeepCoreMiner();
	
	void mine(IAsteroid* ast);
};

#endif
