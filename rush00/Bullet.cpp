#include "Bullet.hpp"

Bullet::Bullet(int x) : _x(x) { return; }

Bullet::~Bullet(void) { return; }

int		Bullet::getX(void) const
{
	return (this->_x);
}