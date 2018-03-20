#ifndef BOCALSTEROID_HPP
# define BOCALSTEROID_HPP

# include "IAsteroid.hpp"

class BocalSteroid : public IAsteroid
{
public:
	BocalSteroid();
	~BocalSteroid();
	
	std::string beMined(DeepCoreMiner *miner) const;
	std::string beMined(StripMiner *miner) const;
	std::string getName(void) const;
};

#endif
