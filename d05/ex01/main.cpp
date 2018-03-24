#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat jim("Jim", 30);
	Form resolution("resolution", 25, 25);

	std::cout << jim;
	std::cout << resolution;

	jim.signForm(resolution);
	jim += 10;
	std::cout << jim;
	jim.signForm(resolution);

	return 0;
}