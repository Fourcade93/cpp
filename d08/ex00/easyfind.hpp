#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <list>
# include <exception>
# include <iostream>

class NotFoundException : public std::exception
{
public:
	NotFoundException() {}
	
	char const * what() const throw()
	{
		return ("Not found");
	}
};

template<typename T>
void	easyfind(T & cont, int n)
{
	if (std::find(cont.begin(), cont.end(), n) == cont.end())
		throw NotFoundException();
	std::cout << "Found \033[0;32m" << n  <<"\033[0m in container" << std::endl;
}

#endif
