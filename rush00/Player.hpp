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

Player::Player(void) : _y(47), _x(49), _lives(10), _points(0)
{
	return;
}

Player::~Player(void) { return; }

int Player::getX(void) const
{
	return (this->_x);
}

int Player::getY(void) const
{
	return (this->_y);
}

int Player::getLives(void) const
{
	return (this->_lives);
}

int Player::getPoints(void) const
{
	return (this->_points);
}

void	Player::moveLeft(void)
{
	(this->_x > 0) ? this->_x-- : this->_x;
}

void	Player::moveRight(void)
{
	(this->_x < 97) ? this->_x++ : this->_x;
}

void	Player::moveTop(void)
{
	(this->_y > 1) ? this->_y-- : this->_y;
}

void	Player::moveBottom(void)
{
	(this->_y < 47) ? this->_y++ : this->_y;
}

int Player::decreaseLives(void)
{
	system("afplay -t 0.5 hit.mp3 > /dev/null &");
	this->_lives--;
	if (!this->_lives)
		return (1);
	return (0);
}

void	Player::increasePoints(int points)
{
	this->_points += points;
}

#endif
