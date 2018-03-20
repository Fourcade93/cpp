#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void)
{
	this->_count = 0;
	return;
}

MiningBarge::~MiningBarge(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_lasers[i];
	}
}

void	MiningBarge::equip(IMiningLaser* laser)
{
	if (this->_count < 4)
	{
		this->_lasers[this->_count] = laser;
		this->_count++;
	}
}

void	MiningBarge::mine(IAsteroid* ast) const
{
	for (int i = 0; i < this->_count; ++i)
	{
		this->_lasers[i]->mine(ast);
	}
}
