#ifndef LINE_HPP
# define LINE_HPP


# include <ncurses.h>
# include "Comet.hpp"

class Line
{
private:
	AEnemy *_enemies[WIN_WIDTH - 2];
	int _count;

	void	shiftEnemies(int ind);

public:
	Line();
	~Line();

	void	print(int y, WINDOW *game_win);
	int checkForKill(int x);
	
};

Line::Line(void)
{
	this->_count = rand() % 2;
	for (int i = 0; i < this->_count; ++i)
	{
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
	for (int i = 0; i < this->_count; ++i)
	{
		if (this->_enemies[i]->getX() == x)
		{
			delete this->_enemies[i];
			this->shiftEnemies(i);
			return (1);
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

#endif
