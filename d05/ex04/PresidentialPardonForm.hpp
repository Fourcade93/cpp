#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <fstream>

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	
	void	beExec(Bureaucrat const & executor) const;
};

#endif
