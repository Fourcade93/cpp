#include <iostream>

template<typename T>
void	iter(T const *arr, int len, void (*f)(T))
{
	for (int i = 0; i < len; ++i)
	{
		f(arr[i]);
	}
}

template<typename T>
void	func(T val)
{
	std::cout << val << std::endl;
}

int main(void)
{
	int n_arr[] = {21, 42, 84};
	char c_arr[] = "I Love Maldive";
	float f_arr[] = {21.21f, 42.42f, 3.14f};

	::iter(n_arr, 3, &::func);
	std::cout << "\033[0;36m";
	::iter(c_arr, sizeof(c_arr) - 1, &::func);
	std::cout << "\033[0m";
	::iter(f_arr, 3, &::func);
	return 0;
}
