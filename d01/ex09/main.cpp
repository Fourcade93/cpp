#include "Logger.hpp"

int main(void)
{
	Logger	tmp("log_file");

	tmp.log("ToFile", "File log");
	tmp.log("ToConsole", "Console log");
	return 0;
}
