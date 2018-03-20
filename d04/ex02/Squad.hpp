#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
private:
	ISpaceMarine *_units[42];
	int _count;
	int _maxCount;

public:
	Squad();
	Squad(Squad &src);
	~Squad();
	
	int getCount() const;
	ISpaceMarine* getUnit(int N) const;
	int push(ISpaceMarine *unit);
	Squad &operator=(Squad const &src);
	ISquad &operator=(ISquad const &src);
};
#endif
