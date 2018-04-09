#ifndef LINE_HPP
# define LINE_HPP


# include <ncurses.h>
# include "Comet.hpp"
# include "Xshot.hpp"
# include "EnemyBullets.hpp"

class EnemyBullets;

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
	int		checkForKill(int x);
	int		checkIfTarget(int x);
	void	addBullets(int y, EnemyBullets *en_shots);
	
};

#endif
