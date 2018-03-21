#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player
{
private:
	int _y;
	int _x;
	int _lives;
public:
	Player();
	~Player();
	
	int getX() const;
	int getY() const;
	int getLives() const;
	void	moveLeft();
	void	moveRight();
	void	moveTop();
	void	moveBottom();
	int decreaseLives();
};

Player::Player(void) : _y(47), _x(49), _lives(10)
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

void	Player::moveLeft(void)
{
	(this->_x > 1) ? this->_x-- : this->_x;
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
	this->_lives--;
	if (!this->_lives)
		return (1);
	return (0);
}

#endif
