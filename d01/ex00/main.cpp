#include "Pony.hpp"

void	print_col(std::string s)
{
	int j = -1;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 9 && s.size() > 10)
			std::cout << ".";
		else if (i + s.size() < 10)
			std::cout << " ";
		else
			std::cout << s[++j];
	}
	std::cout << "|";
}

void	ponyOnTheHeap(void)
{
	std::string s;
	Pony *heap = new Pony();

	std::cout << "Pony \033[0;32m" << heap->name << "\033[0m live on heap.\033[0;33m" << std::endl;
	std::cout << "      Name|     Color|       Age|" << std::endl;
	print_col(heap->name);
	print_col(heap->color);
	print_col(std::to_string(heap->age));
	std::cout << std::endl;
	std::cout << "\033[0mPress enter to kill " << heap->name << std::endl;
	getline(std::cin, s);
	delete heap;
}

void	ponyOnTheStack(void)
{
	std::string s;
	Pony stack;

	std::cout << "Pony \033[0;32m" << stack.name << "\033[0m live on stack.\033[0;33m" << std::endl;
	std::cout << "      Name|     Color|       Age|" << std::endl;
	print_col(stack.name);
	print_col(stack.color);
	print_col(std::to_string(stack.age));
	std::cout << std::endl;
	std::cout << "\033[0mPress enter to kill " << stack.name << std::endl;
	getline(std::cin, s);
}

int main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}