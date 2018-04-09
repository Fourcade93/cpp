
#include "Line.hpp"

Line::Line(void)
{
	this->_count = rand() % 2;
	for (int i = 0; i < this->_count; ++i)
	{
		if (rand() % 4 == 2)
			this->_enemies[i] = new Xshot(rand() % 98);
		else
			this->_enemies[i] = new Comet(rand() % 98);
	}
}

Line::~Line(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_enemies[i];
	}
}

void	Line::print(int y, WINDOW *game_win)
{
	for (int i = 0; i < this->_count; ++i)
	{
		mvwprintw(game_win, y, this->_enemies[i]->getX(), "%C", this->_enemies[i]->getView());
	}
}

int Line::checkForKill(int x)
{
	int ret = 1;

	for (int i = 0; i < this->_count; ++i)
	{
		if (this->_enemies[i]->getX() == x)
		{
			if (this->_enemies[i]->getView() == L'W')
				ret = 4;
			delete this->_enemies[i];
			this->shiftEnemies(i);
			return (ret);
		}
	}
	return (0);
}

void	Line::shiftEnemies(int ind)
{
	while (ind < this->_count - 1)
	{
		this->_enemies[ind] = this->_enemies[ind + 1];
		ind++;
	}
	this->_count--;
}

int		Line::checkIfTarget(int x)
{
	for (int i = 0; i < this->_count; ++i)
	{
		if (this->_enemies[i]->getX() == x)
			return (1);
	}
	return (0);
}

void	Line::addBullets(int y, EnemyBullets *en_shots)
{
	for (int i = 0; i < this->_count; ++i)
	{
		if (this->_enemies[i]->getView() == L'W')
			en_shots->addBullets(y + 1, this->_enemies[i]->getX());
	}
}