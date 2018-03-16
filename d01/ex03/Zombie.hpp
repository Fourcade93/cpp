#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

class Zombie
{
public:
	Zombie(void);
	~Zombie();
	std::string name;
	std::string type;

	void	announce(void);
};

#endif