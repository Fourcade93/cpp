#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	int _count;
	AMateria *_materias[4];

public:
	Character(std::string name);
	Character(Character &src);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria const * getMateria(int idx) const;
	Character & operator=(Character const &src);
	
};

#endif