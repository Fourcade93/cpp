#ifndef BULLETSLINE_HPP
# define BULLETSLINE_HPP

# include "EnemiesMap.hpp"
# include "Bullet.hpp"
# include <ncurses.h>

class EnemiesMap;

class BulletsLine
{
private:
	Bullet *_bullets[WIN_WIDTH - 2];
	int _count;

	void	shiftBullets(int ind);
public:
	BulletsLine();
	~BulletsLine();
	
	void	push(int x);
	int		checkCollision(int y, EnemiesMap *enemies);
	void	print(WINDOW *game_win, int y);
};

BulletsLine::BulletsLine(void) : _count(0) { return; }

BulletsLine::~BulletsLine(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_bullets[i];
	}
	return;
}

void	BulletsLine::push(int x)
{
	this->_bullets[this->_count] = new Bullet(x);
	this->_count++;
}

int		BulletsLine::checkCollision(int y, EnemiesMap *enemies)
{
	for (int i = 0; i < this->_count; ++i)
	{
		if (enemies->checkCollision(y, this->_bullets[i]->getX()))
		{
			delete this->_bullets[i];
			this->shiftBullets(i);
			return (1);
		}
	}
	return (0);
}

void	BulletsLine::shiftBullets(int ind)
{
	while (ind < this->_count - 1)
	{
		this->_bullets[ind] = this->_bullets[ind + 1];
		ind++;
	}
	this->_count--;
}

void	BulletsLine::print(WINDOW *game_win, int y)
{
	for (int i = 0; i < this->_count; ++i)
	{
		mvwprintw(game_win, y, this->_bullets[i]->getX(), "%c", '\"');
	}
}

#endif
