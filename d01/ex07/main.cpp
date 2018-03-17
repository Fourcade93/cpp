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
	std::string::size_type start = 0;
	std::ofstream ofs(std::string(av[1]) + ".replace");

	getline(ifs, str, (char)ifs.eof());
	while ((start = str.find(s1, start)) != std::string::npos)
	{
		str.erase(start, s1.size());
		str.insert(start, s2);
		start += s2.size();
	}
	ofs << str;
	ifs.close();
	ofs.close();
	return 0;
}
