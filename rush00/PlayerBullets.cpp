#ifndef PLAYERBULLETS_CPP
# define PLAYERBULLETS_CPP

#include "PlayerBullets.hpp"

PlayerBullets::PlayerBullets(void)
{
	for (int i = 0; i < 50; ++i)
	{
		this->_lines[i] = NULL;
	}
}

PlayerBullets::~PlayerBullets(void)
{
	for (int i = 0; i < 50; ++i)
	{
		if (this->_lines[i])
			delete this->_lines[i];
	}
	return;
}

void	PlayerBullets::addBullets(int y, int x)
{
	if (!this->_lines[y])
		this->_lines[y] = new BulletsLine;
	this->_lines[y]->push(x);
	system("afplay -t 0.5 pl_shot.mp3 > /dev/null &");
}

void	PlayerBullets::shiftLines(void)
{
	if (this->_lines[0])
		delete this->_lines[0];
	for (int i = 0; i < 49; ++i)
	{
		this->_lines[i] = this->_lines[i + 1];
	}
	this->_lines[49] = NULL;
}

void	PlayerBullets::checkCollision(EnemiesMap *enemies, Player *pl, WINDOW *game_win)
{
	for (int i = 0; i < 50; ++i)
	{
		if (this->_lines[i])
			this->_lines[i]->checkCollision(i, enemies, pl, game_win);
	}
}

void	PlayerBullets::printLines(WINDOW *game_win)
{
	for (int i = 0; i < 50; ++i)
	{
		if (this->_lines[i])
			this->_lines[i]->print(game_win, i);
	}
}

#endif
