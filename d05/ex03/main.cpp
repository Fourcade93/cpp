#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat jim("Jim", 30);
	Bureaucrat bob("Bob", 146);
	Form  *shrubbery = intern.makeForm("shrubbery creation", "garden");
	Form  *robotomy = intern.makeForm("robotomy request", "Gary");
	Form  *pardon = intern.makeForm("presidential pardon", "John");
	Form  *unknown = intern.makeForm("unknown", "John");

	std::cout << "\033[0;32mIntro:" << std::endl << std::endl;
	std::cout << jim;
	std::cout << bob;
	std::cout << *shrubbery;
	std::cout << *robotomy;
	std::cout << *pardon;

	std::cout << std::endl << "\033[0;33mShrubberyCreationForm:" << std::endl << std::endl;
	bob.signForm(*shrubbery);
	bob += 10;
	std::cout << bob;
	bob.signForm(*shrubbery);
	bob.executeForm(*shrubbery);

	std::cout << std::endl << "\033[0;36mRobotomyRequestForm:" << std::endl << std::endl;
	jim.executeForm(*robotomy);
	jim.signForm(*robotomy);
	jim.executeForm(*robotomy);
	jim.executeForm(*robotomy);
	jim.executeForm(*robotomy);
	jim.executeForm(*robotomy);
	jim.executeForm(*robotomy);
	jim.executeForm(*robotomy);

	std::cout << std::endl << "\033[0;35mPresidentialPardonForm:" << std::endl << std::endl;
	jim.signForm(*pardon);
	jim += 10;
	std::cout << jim;
	jim.signForm(*pardon);
	jim.executeForm(*pardon);
	jim += 15;
	std::cout << jim;
	jim.executeForm(*pardon);

	return 0;
}