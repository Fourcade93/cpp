#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	this->_count = 0;
	return;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < this->_count; ++i)
	{
		delete this->_materias[i];
	}
}

void	MateriaSource::learnMateria(AMateria *src)
{
	if (this->_count < 4)
	{
		this->_materias[this->_count] = src->clone();
		this->_count++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_count; ++i)
	{
		if (type == this->_materias[i]->getType())
			return (this->_materias[i]->clone());
	}
	return (NULL);
}
