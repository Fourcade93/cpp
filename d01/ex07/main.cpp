#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		if (ac < 4)
			std::cout << "Not enough arguments." << std::endl;
		else
			std::cout << "Too many arguments." << std::endl;
		return (0);
	}

	std::ifstream ifs(av[1]);
	if (ifs.fail())
	{
		std::cout << "Fileopen error." << std::endl;
		return (0);
	}

	std::string str;
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::ofstream ofs(std::string(av[1]) + ".replace");

	while (getline(ifs, str))
	{
		if (str == s1)
			ofs << s2 << std::endl;
		else
			ofs << str << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
