#ifndef COMET_HPP
# define COMET_HPP

# include "AEnemy.hpp"

class Comet : public AEnemy
{
public:
	Comet(int x) : AEnemy(L'◊', x) {}
	~Comet() {}
};

#endif
