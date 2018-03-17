#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>

struct t_action;

class Human
{
public:
	Human(std::string nname);
	~Human();

	void	action(std::string const & action_name, std::string const & target);

private:
	std::string		_name;
	static t_action	_actions[];
	void	meleeAttack(std::string const & target);
	void	rangeAttack(std::string const & target);
	void	intimidatingShout(std::string const & target);
};

#endif
