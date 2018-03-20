#include "StripMiner.hpp"

StripMiner::StripMiner(void) { return; }

StripMiner::~StripMiner(void) { return; }

void StripMiner::mine(IAsteroid* ast)
{
	std::cout << "* strip mining ... got " + ast->beMined(this) + " ! *" << std::endl;
}
