#ifndef ENEMIESMAP_HPP
# define ENEMIESMAP_HPP

#include "Line.hpp"

class EnemiesMap
{
private:
	Line *_lines[50];
	int _count;
public:
	EnemiesMap();
	~EnemiesMap();
	
	void	addLine();
	void	printLines(WINDOW *game_win);
	int		checkCollision(int y, int x);
};

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
	(this->_count < 47) ? this->_count++ : this->_count;
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

#endif