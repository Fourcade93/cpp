#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	return;
}

Bureaucrat::~Bureaucrat(void) { return; }

std::string const & Bureaucrat::getName(void) const
{
	return (this->_name);
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name + " signs " + form.getName() << std::endl;;
	}
	catch (std::exception & e)
	{
		std::cout << this->_name + " cannot sign " + form.getName() +
			" because " + e.what() << std::endl;;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name + " executes " + form.getName() << std::endl;;
	}
	catch (std::exception & e)
	{
		std::cout << this->_name + " cannot execute " + form.getName() +
			" because " + e.what() << std::endl;;
	}
}

Bureaucrat & Bureaucrat::operator+=(int n)
{
	if (this->_grade - n < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= n;
	return (*this);
}

Bureaucrat & Bureaucrat::operator-=(int n)
{
	if (this->_grade + n > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += n;
	return (*this);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) { return; }

char const * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) { return; }

char const * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & tmp)
{
	os << tmp.getName() + ", bureaucrat grade " << tmp.getGrade() << std::endl;
	return (os);
}
