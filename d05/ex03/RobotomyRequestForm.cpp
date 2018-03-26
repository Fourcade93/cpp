#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", 72, 45), _target(target)
{ return; }

RobotomyRequestForm::~RobotomyRequestForm(void) { return; }

void	RobotomyRequestForm::beExec(Bureaucrat const & executor) const
{
	if (rand() % 2)
		std::cout << "Successfull execution of form!" << std::endl;
	else
		std::cout << "Execution of form was failed!" << std::endl;
}
