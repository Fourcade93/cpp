#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat jim("Jim", 30);
	Bureaucrat bob("Bob", 146);
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("Gary");
	PresidentialPardonForm pardon("John");

	std::cout << "\033[0;32mIntro:" << std::endl << std::endl;
	std::cout << jim;
	std::cout << bob;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;

	std::cout << std::endl << "\033[0;33mShrubberyCreationForm:" << std::endl << std::endl;
	bob.signForm(shrubbery);
	bob += 10;
	std::cout << bob;
	bob.signForm(shrubbery);
	bob.executeForm(shrubbery);

	std::cout << std::endl << "\033[0;36mRobotomyRequestForm:" << std::endl << std::endl;
	jim.executeForm(robotomy);
	jim.signForm(robotomy);
	jim.executeForm(robotomy);
	jim.executeForm(robotomy);
	jim.executeForm(robotomy);
	jim.executeForm(robotomy);
	jim.executeForm(robotomy);
	jim.executeForm(robotomy);

	std::cout << std::endl << "\033[0;35mPresidentialPardonForm:" << std::endl << std::endl;
	jim.signForm(pardon);
	jim += 10;
	std::cout << jim;
	jim.signForm(pardon);
	jim.executeForm(pardon);
	jim += 15;
	std::cout << jim;
	jim.executeForm(pardon);

	return 0;
}