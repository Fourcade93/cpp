#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNDEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		for (int j = 0; av[i][j]; ++j)
		{
			av[i][j] = ((av[i][j] >= 'a' && av[i][j] <= 'z') ? av[i][j] - 32 : av[i][j]);
		}
		std::cout << av[i];
	}
	std::cout << std::endl;
	return 0;
}