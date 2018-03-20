#ifndef ASTEROBOCAL_HPP
# define ASTEROBOCAL_HPP

# include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid
{
public:
	AsteroBocal();
	~AsteroBocal();
	
	std::string beMined(DeepCoreMiner *miner) const;
	std::string beMined(StripMiner *miner) const;
	std::string getName(void) const;
};

#endif
