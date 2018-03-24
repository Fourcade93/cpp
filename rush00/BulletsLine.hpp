#ifndef BULLETSLINE_HPP
# define BULLETSLINE_HPP

# include "ABulletsLine.hpp"
# include "EnemiesMap.hpp"
# include <ncurses.h>

class EnemiesMap;

class BulletsLine : public ABulletsLine
{
protected:
	void	shiftBullets(int ind);
public:
	BulletsLine() {}

	~BulletsLine();

	void		checkCollision(int y, EnemiesMap *enemies, Player *pl, WINDOW *game_win);
};

BulletsLine::~BulletsLine(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_bullets[i];
	}
	return;
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

void		BulletsLine::checkCollision(int y, EnemiesMap *enemies, Player *pl, WINDOW *game_win)
{
	int points;

	for (int i = 0; i < this->_count; ++i)
	{
		if ((points = enemies->checkCollision(y, this->_bullets[i]->getX())))
		{
			system("afplay -t 0.5 burst.mp3 > /dev/null &");
			mvwprintw(game_win, y, this->_bullets[i]->getX(), "%C", L'💥');
			wrefresh(game_win);
			usleep(80000);
			pl->increasePoints(points);
			delete this->_bullets[i];
			this->shiftBullets(i--);
		}
	}
}

#endif
