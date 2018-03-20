#include "Squad.hpp"

Squad::Squad(void)
{
	this->_count = 0;
	this->_maxCount = 42;
	return;
}

Squad::Squad(Squad &src)
{
	*this = src;
}

Squad::~Squad(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_units[i];
	}
}

int Squad::getCount(void) const
{
	return (this->_count);
}

ISpaceMarine* Squad::getUnit(int N) const
{
	if (N < this->_count)
		return (this->_units[N]);
	return (NULL);
}

int Squad::push(ISpaceMarine * unit)
{
	if (this->_count < this->_maxCount)
	{
		this->_units[this->_count] = unit;
		this->_count += 1;
	}
	return (this->_count);
}

Squad &Squad::operator=(Squad const &src)
{
	if (this != &src)
	{
		int stop = (this->_count > src.getCount()) ? this->_count : src.getCount();
		for (int i = 0; i < stop; ++i)
		{
			if (i < this->_count)
				delete this->_units[i];
			if (i < src.getCount())
				this->_units[i] = src.getUnit(i)->clone();
		}
		this->_count = src.getCount();
	}
	return (*this);
}

ISquad &Squad::operator=(ISquad const &src)
{
	if (this != &src)
	{
		int stop = (this->_count > src.getCount()) ? this->_count : src.getCount();
		for (int i = 0; i < stop; ++i)
		{
			if (i < this->_count)
				delete this->_units[i];
			if (i < src.getCount())
				this->_units[i] = src.getUnit(i)->clone();
		}
		this->_count = src.getCount();
	}
	return (*this);
}
