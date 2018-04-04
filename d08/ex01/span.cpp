#include "span.hpp"

Span::Span(unsigned int total) : _total(total), _nums(total)
{
	this->_count = 0;
}

Span::~Span(void) {}

void	Span::addNumber(int n)
{
	if (this->_count == this->_total)
		throw Span::FullException();
	this->_nums[this->_count] = n;
	this->_count++;
	if (this->_count == 1)
	{
		this->_min = n;
		this->_max = n;
		this->_avrgMin = n;
	}
	else if (n < this->_min)
	{
		this->_avrgMin = this->_min;
		this->_min = n;
	}
	else if (n > this->_max)
		this->_max = n;
}

int		Span::shortestSpan(void)
{
	if (this->_count < 2)
		throw Span::NotFoundException();
	return (Span::_abs(this->_avrgMin) - Span::_abs(this->_min));
}

int		Span::longestSpan(void)
{
	if (this->_count < 2)
		throw Span::NotFoundException();
	return (Span::_abs(this->_max) - Span::_abs(this->_min));
}

Span::FullException::FullException(void) {}

char const * Span::FullException::what() const throw()
{
	return ("Container is full!");
}

Span::NotFoundException::NotFoundException(void) {}

char const * Span::NotFoundException::what() const throw()
{
	return ("Too few elements!");
}

int		Span::_abs(int n)
{
	return (n < 0 ? -n : n);
}
