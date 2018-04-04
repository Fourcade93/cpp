#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
private:
	unsigned int _total;
	unsigned int _count;
	std::vector<int> _nums;
	int		_min;
	int		_avrgMin;
	int		_max;
	static int	_abs(int n);
	
public:
	Span(unsigned int total);
	~Span();
	
	void	addNumber(int n);
	int		shortestSpan(void);
	int		longestSpan(void);

	class FullException : public std::exception
	{
	public:
		FullException();
		
		char const * what() const throw();
	};

	class NotFoundException : public std::exception
	{
	public:
		NotFoundException();
		
		char const * what() const throw();
	};
};

#endif
