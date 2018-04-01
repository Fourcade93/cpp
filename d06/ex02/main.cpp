#include "ABC.hpp"
#include <iostream>

Base *generate(void)
{
	std::srand(std::time(0));
	Base *ret;
	int n = rand() % 3;

	if (!n)
		ret = new A;
	else if (n == 1)
		ret = new B;
	else
		ret = new C;
	return (ret);
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base & p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

int main(void)
{
	Base *ptr = generate();

	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	return 0;
}
