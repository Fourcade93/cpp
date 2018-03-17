#include "Fixed.hpp"

Fixed::Fixed(void) : _val(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & tmp)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_val = tmp.getRawBits();
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

Fixed & Fixed::operator=(Fixed const & tmp)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_val = tmp.getRawBits();
	return (*this);
}

int const Fixed::_frBits = 8;
