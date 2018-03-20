#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	unsigned int xp_;
	std::string _type;
public:
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	virtual ~AMateria() {}

	std::string const & getType() const;
	unsigned int getXP() const;
	void	increaseXP();
	AMateria & operator=(AMateria const & src);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
	
};

#endif