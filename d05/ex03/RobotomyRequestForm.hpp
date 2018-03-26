#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <fstream>

class RobotomyRequestForm : public Form
{
private:
	std::string _target;

public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	
	void	beExec(Bureaucrat const & executor) const;
};

#endif
