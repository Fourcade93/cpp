#ifndef HUMAN_H
# define HUMAN_H

# include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();
	
	Brain const brain;
	Brain const & getBrain(void);
	std::string identify(void) const;
};
#endif