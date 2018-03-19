#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
{
	this->_hp = hp;
	this->_type = type;
}

Enemy::~Enemy(void) { return; }

void Enemy::takeDamage(int damage)
{
	if (damage > 0)
		this->_hp = (this->_hp < damage) ? 0 : this->_hp - damage;
}

std::string const & Enemy::getType(void) const
{
	return (this->_type);
}

int Enemy::getHP(void) const
{
	return (this->_hp);
}

void	Enemy::setHP(int hp)
{
	this->_hp = hp;
}
