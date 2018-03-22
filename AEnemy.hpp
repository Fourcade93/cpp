#ifndef AENEMY_HPP
# define AENEMY_HPP

class AEnemy
{
private:
	wchar_t _view;
	int _x;
public:
	AEnemy(wchar_t view, int x) : _view(view), _x(x) {}
	virtual ~AEnemy() {}

	wchar_t	getView(void) const { return (this->_view); }

	int	getX(void) const { return (this->_x); }
};

#endif
