#ifndef BULLET_HPP
# define BULLET_HPP

class Bullet
{
private:
	int _x;
public:
	Bullet(int x);
	~Bullet();
	
	int		getX() const;
};

Bullet::Bullet(int x) : _x(x) { return; }

Bullet::~Bullet(void) { return; }

int		Bullet::getX(void) const
{
	return (this->_x);
}

#endif
