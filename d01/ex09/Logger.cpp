#include "Logger.hpp"

Logger::Logger(std::string filename) : _file(filename) { return; }

Logger::~Logger(void) { return; }

struct t_logger
{
	std::string name;
	void		(Logger::*func)(std::string const &);
};

t_logger	Logger::_loggers[2] = {
	{"ToConsole", &Logger::logToConsole},
	{"ToFile", &Logger::logToFile}
};

void	Logger::logToConsole(std::string const & msg)
{
	std::cout << msg << std::endl;
}

void	Logger::logToFile(std::string const & msg)
{
	std::ofstream ofs;
	ofs.open(this->_file, std::ofstream::out | std::ofstream::app);
	ofs << msg << std::endl;
	ofs.close();
}

std::string	Logger::makeLogEntry(std::string const & msg)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buf[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buf, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
	std::string ret = std::string(buf) + " log message: " + msg;
	return (ret);
}

void	Logger::log(std::string const & dest, std::string const & message)
{
	int i = -1;

	while (++i < 2)
		if (this->_loggers[i].name == dest)
		{
			(this->*_loggers[i].func)(this->makeLogEntry(message));
		}
}
