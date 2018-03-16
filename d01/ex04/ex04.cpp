#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << "\033[0;32mThis is a string: \033[1;32m" + str << std::endl;
	std::cout << "\033[0;33mThis is a pointer to string: \033[1;33m" + *ptr << std::endl;
	std::cout << "\033[0;35mThis is a reference of a string: \033[1;35m" + ref << std::endl;
	return 0;
}
