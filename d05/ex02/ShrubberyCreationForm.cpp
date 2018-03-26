#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 145, 137), _target(target)
{ return; }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { return; }

void	ShrubberyCreationForm::beExec(Bureaucrat const & executor) const
{
	std::ofstream ofs(this->_target + "_srubbery");

	if (ofs)
	{
		ofs << "               ,@@@@@@@," << std::endl <<
				"       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
				"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
				"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
				"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
				"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
				"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
				"       |o|        | |         | |" << std::endl <<
				"       |.|        | |         | |" << std::endl <<
				"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		ofs.close();
	}
}
