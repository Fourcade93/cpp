#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
public:
	StripMiner();
	~StripMiner();
	
	void mine(IAsteroid* ast);
};

#endif
