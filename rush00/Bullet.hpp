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

#endif
