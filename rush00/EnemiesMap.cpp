#include "EnemiesMap.hpp"

EnemiesMap::EnemiesMap(void) : _count(0) {}

EnemiesMap::~EnemiesMap(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_lines[i];
	}
}

void	EnemiesMap::addLine(void)
{
	if (this->_count == 48)
		delete this->_lines[47];
	for (int i = this->_count; i > 0; --i)
	{
		this->_lines[i] = this->_lines[i - 1];
	}
	this->_lines[0] = new Line;
	(this->_count < 48) ? this->_count++ : this->_count;
}

void	EnemiesMap::printLines(WINDOW *game_win)
{
	for (int i = 0; i < this->_count; ++i)
	{
		this->_lines[i]->print(i + 1, game_win);
	}
}

int		EnemiesMap::checkCollision(int y, int x)
{
	if (this->_count > y)
		return (this->_lines[y]->checkForKill(x));
	return (0);
}

int		EnemiesMap::checkIfTarget(int y, int x)
{
	y = (this->_count < y) ? this->_count : y;
	for (int i = 0; i < y; ++i)
	{
		if (this->_lines[i]->checkIfTarget(x))
			return (1);
	}
	return (0);
}

void	EnemiesMap::addBullets(EnemyBullets *en_shots)
{
	for (int i = 0; i < this->_count; ++i)
	{
		this->_lines[i]->addBullets(i, en_shots);
	}
}