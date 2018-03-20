#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	int _count;
	AMateria *_materias[4];

public:
	MateriaSource();
	~MateriaSource();
	
	void learnMateria(AMateria *src);
	AMateria* createMateria(std::string const & type);
};

#endif