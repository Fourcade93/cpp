#ifndef ENEMYBULLETSLINE_HPP
# define ENEMYBULLETSLINE_HPP

# include "ABulletsLine.hpp"
# include "EnemiesMap.hpp"

class EnemyBulletsLine : public ABulletsLine
{
protected:
	void	shiftBullets(int ind);
public:
	EnemyBulletsLine();

	~EnemyBulletsLine();

	void		checkCollision(Player *pl);
};

#endif
