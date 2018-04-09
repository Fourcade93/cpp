#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player
{
private:
	int _y;
	int _x;
	int _lives;
	int _points;
public:
	Player();
	~Player();
	
	int		getX() const;
	int		getY() const;
	int		getLives() const;
	int		getPoints() const;
	void	moveLeft();
	void	moveRight();
	void	moveTop();
	void	moveBottom();
	int		decreaseLives();
	void	increasePoints(int points);
};

#endif
