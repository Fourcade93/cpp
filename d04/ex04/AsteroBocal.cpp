#include "AsteroBocal.hpp"

AsteroBocal::AsteroBocal(void) { return; }

AsteroBocal::~AsteroBocal(void) { return; }

std::string AsteroBocal::beMined(DeepCoreMiner *miner) const
{
	return ("Thorite");
}

std::string AsteroBocal::beMined(StripMiner *miner) const
{
	return ("Flavium");
}

std::string AsteroBocal::getName(void) const
{
	return ("AsteroBocal");
}
