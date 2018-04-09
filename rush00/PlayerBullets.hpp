#ifndef PLAYERBULLETS_HPP
# define PLAYERBULLETS_HPP

# include "BulletsLine.hpp"

class PlayerBullets
{
private:
	BulletsLine *_lines[50];
public:
	PlayerBullets();
	~PlayerBullets();
	
	void	addBullets(int y, int x);
	void	shiftLines();
	void	checkCollision(EnemiesMap *enemies, Player *pl, WINDOW *game_win);
	void	printLines(WINDOW *game_win);
};

#endif
