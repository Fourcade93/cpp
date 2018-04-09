#ifndef ABULLETSLINE_HPP
# define ABULLETSLINE_HPP

# include "Player.hpp"
# include "Bullet.hpp"
# include "ft_retro.hpp"


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

#endif