#include "ABulletsLine.hpp"

ABulletsLine::ABulletsLine(void) : _count(0) { return; }

void	ABulletsLine::push(int x)
{
	this->_bullets[this->_count] = new Bullet(x);
	this->_count++;
}

void	ABulletsLine::print(WINDOW *game_win, int y)
{
	for (int i = 0; i < this->_count; ++i)
	{
		mvwprintw(game_win, y, this->_bullets[i]->getX(), "%c", '\'');
	}
}