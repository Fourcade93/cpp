#include "serial.hpp"
#include <ctime>

void	*serialize(void)
{
	SerialData *ret = new SerialData;
	char rand_char[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::srand(std::time(0));
	for (int i = 0; i < 8; ++i)
	{
		ret->s1[i] = rand_char[rand() % 62];
		ret->s2[i] = rand_char[rand() % 62];
	}
	ret->s1[8] = '\0';
	ret->s2[8] = '\0';
	ret->n = rand();
	ret->n = (rand() % 2) ? -ret->n : ret->n;
	return (reinterpret_cast<void*>(ret));
}