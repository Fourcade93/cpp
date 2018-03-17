#include "Human.hpp"

Human::Human(std::string nname) : _name(nname) { return; }
Human::~Human(void) { return; }


struct t_action
{
	std::string name;
	void		(Human::*func)(std::string const &);
};

t_action	Human::_actions[3] = {
	{"meleeAttack", &Human::meleeAttack},
	{"rangeAttack", &Human::rangeAttack},
	{"intimidatingShout", &Human::intimidatingShout}
};

void	Human::meleeAttack(std::string const & target)
{
	std::cout << this->_name + " meleeAttack to " + target << std::endl;
}

void	Human::rangeAttack(std::string const & target)
{
	std::cout << this->_name + " rangeAttack to " + target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << this->_name + " intimidatingShout to " + target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	int i = -1;
	while (++i < 3)
	{
		if (this->_actions[i].name == action_name)
		{
			(this->*_actions[i].func)(target);
			break;
		}
	}
}
