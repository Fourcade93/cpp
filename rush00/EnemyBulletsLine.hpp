#ifndef ENEMYBULLETSLINE_HPP
# define ENEMYBULLETSLINE_HPP

# include "ABulletsLine.hpp"
# include "EnemiesMap.hpp"


class EnemyBulletsLine : public ABulletsLine
{
protected:
	void	shiftBullets(int ind);
public:
	EnemyBulletsLine() {}

	~EnemyBulletsLine();

	void		checkCollision(Player *pl);
};

EnemyBulletsLine::~EnemyBulletsLine(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_bullets[i];
	}
	return;
}

void	EnemyBulletsLine::shiftBullets(int ind)
{
	while (ind < this->_count - 1)
	{
		this->_bullets[ind] = this->_bullets[ind + 1];
		ind++;
	}
	this->_count--;
}

void		EnemyBulletsLine::checkCollision(Player *pl)
{
	for (int i = 0; i < this->_count; ++i)
	{
		if (pl->getX() == this->_bullets[i]->getX())
		{
			system("afplay -t 0.5 hit.mp3 > /dev/null &");
			pl->decreaseLives();
			delete this->_bullets[i];
			this->shiftBullets(i);
			return;
		}
	}
}

#endif
