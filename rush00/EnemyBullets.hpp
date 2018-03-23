#ifndef ENEMYBULLETS_HPP
# define ENEMYBULLETS_HPP

# include "EnemyBulletsLine.hpp"

class EnemyBullets
{
private:
	EnemyBulletsLine *_lines[50];
public:
	EnemyBullets();
	~EnemyBullets();
	
	void	addBullets(int y, int x);
	void	shiftLines();
	void	checkCollision(Player *pl);
	void	printLines(WINDOW *game_win);
};

EnemyBullets::EnemyBullets(void)
{
	for (int i = 0; i < 50; ++i)
	{
		this->_lines[i] = NULL;
	}
}

EnemyBullets::~EnemyBullets(void)
{
	for (int i = 0; i < 50; ++i)
	{
		if (this->_lines[i])
			delete this->_lines[i];
	}
	return;
}

void	EnemyBullets::addBullets(int y, int x)
{
	if (y > 49)
		return;
	if (!this->_lines[y])
		this->_lines[y] = new EnemyBulletsLine;
	this->_lines[y]->push(x);
}

void	EnemyBullets::shiftLines(void)
{
	if (this->_lines[49])
		delete this->_lines[49];
	for (int i = 49; i > 0; --i)
	{
		this->_lines[i] = this->_lines[i - 1];
	}
	this->_lines[0] = NULL;
}

void	EnemyBullets::checkCollision(Player *pl)
{
		if (this->_lines[pl->getY()])
			this->_lines[pl->getY()]->checkCollision(pl);
}

void	EnemyBullets::printLines(WINDOW *game_win)
{
	for (int i = 0; i < 50; ++i)
	{
		if (this->_lines[i])
			this->_lines[i]->print(game_win, i);
	}
}

#endif
