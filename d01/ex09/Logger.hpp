#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <ctime>

struct t_logger;

class Logger
{
public:
	Logger(std::string filename);
	~Logger();
	
	void	log(std::string const & dest, std::string const & message);

private:
	std::string	_file;
	static t_logger	_loggers[];

	void	logToConsole(std::string const & msg);
	void	logToFile(std::string const & msg);
	std::string makeLogEntry(std::string const & msg);
};

#endif
