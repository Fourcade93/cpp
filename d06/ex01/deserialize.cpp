#include "serial.hpp"

Data	*deserialize(void *raw)
{
	SerialData *data = reinterpret_cast<SerialData*>(raw);
	Data *ret = new Data;

	ret->s1 = std::string(data->s1);
	ret->n = data->n;
	ret->s2 = std::string(data->s2);
	return (ret);
}