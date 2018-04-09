#ifndef AENEMY_HPP
# define AENEMY_HPP

class AEnemy
{
private:
	wchar_t _view;
	int _x;
public:
	AEnemy(wchar_t view, int x);
	virtual ~AEnemy();

	wchar_t	getView(void) const;

	int	getX(void) const;
};

#endif
