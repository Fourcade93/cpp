#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & tmp);
	Fixed(int const val);
	Fixed(float const val);
	~Fixed();

	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed & operator=(Fixed const & tmp);

private:
	int _val;
	static int const _frBits;
	
};

std::ostream & operator<<(std::ostream & os, Fixed const & tmp); 

#endif
