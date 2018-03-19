#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
private:
	std::string _type;
	int _hp;

public:
	Enemy(int hp, std::string const & type);
	virtual ~Enemy();
	
	std::string const & getType() const;
	int getHP() const;
	void setHP(int hp);

	virtual void takeDamage(int);
};

#endif