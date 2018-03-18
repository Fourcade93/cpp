#include "Fixed.hpp"


Fixed::Fixed(void) : _val(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & tmp)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = tmp;
	return;
}

Fixed::Fixed(int const val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_val = val << this->_frBits;
	return;
}

Fixed::Fixed(float const val)
{

	std::cout << "Float constructor called" << std::endl;
	this->_val = (int)roundf(val * (1 << this->_frBits));
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

int Fixed::toInt(void) const
{
	return (this->_val >> this->_frBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_val / (1 << this->_frBits));
}

Fixed & Fixed::operator=(Fixed const & tmp)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_val = tmp._val;
	return (*this);
}

bool Fixed::operator>(Fixed const & tmp)
{
	std::cout << "Greater operator called" << std::endl;
	return (this->_val > tmp._val);
}

bool Fixed::operator<(Fixed const & tmp)
{
	std::cout << "Lower operator called" << std::endl;
	return (this->_val > tmp._val);
}

bool Fixed::operator>=(Fixed const & tmp)
{
	std::cout << "Greater or equal operator called" << std::endl;
	return (this->_val >= tmp._val);
}

bool Fixed::operator<=(Fixed const & tmp)
{
	std::cout << "Lower or equal operator called" << std::endl;
	return (this->_val <= tmp._val);
}

bool Fixed::operator==(Fixed const & tmp)
{
	std::cout << "Equal operator called" << std::endl;
	return (this->_val == tmp._val);
}

bool Fixed::operator!=(Fixed const & tmp)
{
	std::cout << "Not equal operator called" << std::endl;
	return (this->_val != tmp._val);
}

Fixed & Fixed::operator+(Fixed const & tmp) const
{
	std::cout << "Addition operator called" << std::endl;
	return (*(new Fixed(this->toFloat() + tmp.toFloat())));
}

Fixed & Fixed::operator-(Fixed const & tmp) const
{
	std::cout << "Subtract operator called" << std::endl;
	return (*(new Fixed(this->toFloat() - tmp.toFloat())));
}

Fixed & Fixed::operator*(Fixed const & tmp) const
{
	std::cout << "Multiplication operator called" << std::endl;
	return (*(new Fixed(this->toFloat() * tmp.toFloat())));
}

Fixed & Fixed::operator/(Fixed const & tmp) const
{
	std::cout << "Division operator called" << std::endl;
	return (*(new Fixed(this->toFloat() / tmp.toFloat())));
}

Fixed & Fixed::operator++(void)
{
	std::cout << "Prefix increment operator called" << std::endl;
	this->_val++;
	return (*this);
}

Fixed const Fixed::operator++(int)
{
	std::cout << "Postfix increment operator called" << std::endl;
	Fixed *ret = new Fixed(*this);
	this->_val++;
	return (*ret);
}

Fixed & Fixed::operator--(void)
{
	std::cout << "Prefix decrement operator called" << std::endl;
	this->_val--;
	return (*this);
}

Fixed const Fixed::operator--(int)
{
	std::cout << "Postfix decrement operator called" << std::endl;
	Fixed *ret = new Fixed(*this);
	this->_val--;
	return (*ret);
}

Fixed & Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1._val < f2._val)
		return (f1);
	return (f2);
}

Fixed const & Fixed::min(Fixed const & f1, Fixed const & f2)
{
	if (f1._val < f2._val)
		return (f1);
	return (f2);
}

Fixed & Fixed::max(Fixed & f1, Fixed & f2)
{
	if (f1._val > f2._val)
		return (f1);
	return (f2);
}

Fixed const & Fixed::max(Fixed const & f1, Fixed const & f2)
{
	if (f1._val > f2._val)
		return (f1);
	return (f2);
}

int const Fixed::_frBits = 8;

std::ostream & operator<<(std::ostream & os, Fixed const & tmp)
{
	os << tmp.toFloat();
	return (os);
}
