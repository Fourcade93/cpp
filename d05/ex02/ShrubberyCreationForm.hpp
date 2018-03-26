#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;

public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	
	void	beExec(Bureaucrat const & executor) const;
};

#endif
