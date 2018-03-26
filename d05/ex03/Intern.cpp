#include "Intern.hpp"

Intern::Intern(void) { return; }

Intern::~Intern(void) { return; }

Form * Intern::makeForm(std::string form, std::string target)
{
	if (form == "robotomy request")
	{
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (form == "shrubbery creation")
	{
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (form == "presidential pardon")
	{
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << "Unknown form." << std::endl;
		return (NULL);
	}
}
