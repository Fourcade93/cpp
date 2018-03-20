#include "Character.hpp"

Character::Character(std::string name)
{
	this->_name = name;
	this->_count = 0;
	return;
}

Character::Character(Character &src)
{
	*this = src;
}

Character::~Character(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_materias[i];
	}
}

std::string const & Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (this->_count < 4)
	{
		this->_materias[this->_count] = m;
		this->_count++;
	}
}

void Character::unequip(int idx)
{
	if (idx < this->_count && idx >= 0)
	{
		for (int i = idx; i < this->_count + 1; ++i)
		{
			this->_materias[i] = this->_materias[i + 1];
		}
		this->_count--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < this->_count && idx >= 0)
		this->_materias[idx]->use(target);
}

AMateria const * Character::getMateria(int idx) const
{
	if (idx < this->_count && idx >= 0)
		return (this->_materias[idx]);
	return (NULL);
}

Character & Character::operator=(Character const &src)
{
	if (this != &src)
	{
		int stop = (this->_count > src._count) ? this->_count : src._count;
		for (int i = 0; i < stop; ++i)
		{
			if (i < this->_count)
				delete this->_materias[i];
			if (i < src._count)
				this->_materias[i] = src.getMateria(i)->clone();
		}
	}
	return (*this);
}
