#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	int _gradeToSign;
	int _gradeToExec;
	bool _ind;
public:
	Form(std::string name, int sign, int exec);
	virtual ~Form();
	
	std::string const &	getName() const;
	int		getGradeToSign() const;
	int		getGradeToExec() const;
	bool	getIndicator() const;
	void	beSigned(Bureaucrat & tmp);
	void	execute(Bureaucrat const & executor) const;
	virtual void	beExec(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();

		char const * what() const throw();
		
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();

		char const * what() const throw();
		
	};

	class NotSignedException : public std::exception
	{
	public:
		NotSignedException();
		
		char const * what() const throw();		
	};
};

std::ostream & operator<<(std::ostream & os, Form const & tmp);

#endif
