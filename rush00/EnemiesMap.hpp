#ifndef ENEMIESMAP_HPP
# define ENEMIESMAP_HPP

# include "Line.hpp"

class Line;
class EnemyBullets;

class EnemiesMap
{
private:
	Line *_lines[50];
	int _count;
public:
	EnemiesMap();
	~EnemiesMap();
	
	void	addLine();
	void	printLines(WINDOW *game_win);
	int		checkCollision(int y, int x);
	int		checkIfTarget(int y, int x);
	void	addBullets(EnemyBullets *en_shots);
};

#endif
