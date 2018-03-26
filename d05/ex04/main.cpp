#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat jim("Jim", 5);
	Bureaucrat bob("Bob", 20);
	OfficeBlock ob;

	ob.setIntern(intern);
	ob.setSigner(bob);
	ob.setExecutor(jim);

	try
	{
		ob.doBureaucracy("presidential pardon", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}