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

int const Fixed::_frBits = 8;

std::ostream & operator<<(std::ostream & os, Fixed const & tmp)
{
	os << tmp.toFloat();
	return (os);
}
