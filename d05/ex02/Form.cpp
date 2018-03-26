#include "Form.hpp"

Form::Form(std::string name, int sign, int exec) : _name(name), _ind(false)
{
	if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	this->_gradeToSign = sign;
	this->_gradeToExec = exec;
	return;
}

Form::~Form(void) { return; }

std::string const & Form::getName(void) const
{
	return (this->_name);
}

int		Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int		Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

bool	Form::getIndicator(void) const
{
	return (this->_ind);
}

void	Form::beSigned(Bureaucrat & tmp)
{
	if (tmp.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_ind = true;
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeToExec)
		throw Form::GradeTooLowException();
	else if (this->_ind == false)
		throw Form::NotSignedException();
	this->beExec(executor);
}

Form::GradeTooHighException::GradeTooHighException(void) { return; }

char const * Form::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

Form::GradeTooLowException::GradeTooLowException(void) { return; }

char const * Form::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

Form::NotSignedException::NotSignedException(void) { return; }

char const * Form::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream & operator<<(std::ostream & os, Form const & tmp)
{
	os << tmp.getName() + ", form sign grade " << tmp.getGradeToSign() <<
		", form exec grade " << tmp.getGradeToExec() << std::endl;
	return (os);
}
