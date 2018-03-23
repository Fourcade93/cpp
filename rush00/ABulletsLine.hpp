#ifndef ABULLETSLINE_HPP
# define ABULLETSLINE_HPP

// # include "EnemiesMap.hpp"
# include "Player.hpp"
# include "Bullet.hpp"
# include "ft_retro.hpp"

// class EnemiesMap;
// class Bullet;

class ABulletsLine
{
protected:
	Bullet *_bullets[WIN_WIDTH - 2];
	int _count;
	virtual void	shiftBullets(int ind) = 0;

public:
	ABulletsLine();
	virtual ~ABulletsLine() {}
	
	void	push(int x);
	// void	checkCollision(int y, EnemiesMap *enemies, Player *pl);
	// void	checkCollision(Player *pl);
	// virtual void checkCollision() = 0;
	void	print(WINDOW *game_win, int y);
};

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

#endif
