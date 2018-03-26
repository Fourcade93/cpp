#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <exception>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

class OfficeBlock
{
private:
	Intern *_intern;
	Bureaucrat *_signer;
	Bureaucrat *_executor;
	Form *_form;

public:
	OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
	OfficeBlock(Intern & intern, Bureaucrat & signer, Bureaucrat & executor);
	OfficeBlock();
	~OfficeBlock();
	
	void	setIntern(Intern intern);
	void	setSigner(Bureaucrat signer);
	void	setExecutor(Bureaucrat executor);
	void	doBureaucracy(std::string form, std::string target);

	class noInternException : public std::exception
	{
	public:
		noInternException();

		char const * what() const throw();
		
	};

	class noSignerException : public std::exception
	{
	public:
		noSignerException();

		char const * what() const throw();
		
	};

	class noExecutorException : public std::exception
	{
	public:
		noExecutorException();

		char const * what() const throw();
		
	};

	class unknownFormException : public std::exception
	{
	public:
		unknownFormException();

		char const * what() const throw();
		
	};
};

#endif
