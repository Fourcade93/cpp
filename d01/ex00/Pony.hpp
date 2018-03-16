#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony
{
public:
	std::string name;
	std::string color;
	int age;
	Pony(void);
	~Pony(void);
};

#endif