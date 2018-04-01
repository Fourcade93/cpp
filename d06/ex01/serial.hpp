#ifndef SERIAL_HPP
# define SERIAL_HPP

# include <iostream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

struct SerialData
{
	char s1[9];
	int n;
	char s2[9];
};

void	*serialize(void);
Data	*deserialize(void *raw);

#endif
