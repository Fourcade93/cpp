#include "MiningBarge.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "AsteroBocal.hpp"
#include "BocalSteroid.hpp"

int main(void)
{
	IAsteroid *ast1 = new AsteroBocal;
	IAsteroid *ast2 = new BocalSteroid;
	IMiningLaser *deep = new DeepCoreMiner;
	IMiningLaser *strip = new StripMiner;

	MiningBarge* barge = new MiningBarge;
	barge->equip(deep);
	barge->equip(strip);

	barge->mine(ast1);
	barge->mine(ast2);
	return 0;
}