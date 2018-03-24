#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	
	std::string const &	getName() const;
	int	getGrade() const;
	Bureaucrat & operator+=(int n);
	Bureaucrat & operator-=(int n);

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
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & tmp);

#endif
