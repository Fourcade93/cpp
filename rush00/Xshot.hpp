#ifndef XSHOT_HPP
# define XSHOT_HPP

# include "AEnemy.hpp"

class Xshot : public AEnemy
{
public:
	Xshot(int x) : AEnemy(L'W', x) {}
	~Xshot() {}
};

#endif
