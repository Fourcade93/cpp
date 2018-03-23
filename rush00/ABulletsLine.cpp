# include "ABulletsLine.hpp"

// class EnemiesMap;

ABulletsLine::ABulletsLine(void) : _count(0) { return; }

void	ABulletsLine::push(int x)
{
	this->_bullets[this->_count] = new Bullet(x);
	this->_count++;
}

// void		ABulletsLine::checkCollision(int y, EnemiesMap *enemies, Player *pl)
// {
// 	for (int i = 0; i < this->_count; ++i)
// 	{
// 		if (enemies->checkCollision(y, this->_bullets[i]->getX()))
// 		{
// 			pl->increasePoints();
// 			delete this->_bullets[i];
// 			this->shiftBullets(i--);
// 		}
// 	}
// }

// void		ABulletsLine::checkCollision(Player *pl)
// {
// 	for (int i = 0; i < this->_count; ++i)
// 	{
// 		if (pl->getX() == this->_bullets[i]->getX())
// 		{
// 			pl->decreaseLives();
// 			delete this->_bullets[i];
// 			this->shiftBullets(i);
// 			return;
// 		}
// 	}
// }

void	ABulletsLine::print(WINDOW *game_win, int y)
{
	for (int i = 0; i < this->_count; ++i)
	{
		mvwprintw(game_win, y, this->_bullets[i]->getX(), "%c", '\'');
	}
}

