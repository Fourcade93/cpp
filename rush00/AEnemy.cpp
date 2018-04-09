#include "AEnemy.hpp"

AEnemy::AEnemy(wchar_t view, int x) : _view(view), _x(x) {}
AEnemy::~AEnemy() {}

wchar_t	AEnemy::getView(void) const { return (this->_view); }

int	AEnemy::getX(void) const { return (this->_x); }