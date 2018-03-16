#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent();
	~ZombieEvent();
	
	void setZombieType(std::string new_type);
	Zombie*	newZombie(std::string name);
	void randomChump(void);
private:
	std::string _type;
};

#endif