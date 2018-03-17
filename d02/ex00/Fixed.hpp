#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & tmp);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed & operator=(Fixed const & tmp);

private:
	int _val;
	static int const _frBits;
	
};

#endif
