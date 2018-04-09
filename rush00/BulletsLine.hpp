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

#endif
