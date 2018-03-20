#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void) { return; }

DeepCoreMiner::~DeepCoreMiner(void) { return; }

void DeepCoreMiner::mine(IAsteroid* ast)
{
	std::cout << "* mining deep ... got " + ast->beMined(this) + " ! *" << std::endl;
}
