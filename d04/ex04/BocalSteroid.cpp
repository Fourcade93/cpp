#include "BocalSteroid.hpp"

BocalSteroid::BocalSteroid(void) { return; }

BocalSteroid::~BocalSteroid(void) { return; }

std::string BocalSteroid::beMined(DeepCoreMiner *miner) const
{
	return ("Zazium");
}

std::string BocalSteroid::beMined(StripMiner *miner) const
{
	return ("Krpite");
}

std::string BocalSteroid::getName(void) const
{
	return ("BocalSteroid");
}
