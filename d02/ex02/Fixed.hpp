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

	Fixed & operator+(Fixed const & tmp) const;
	Fixed & operator-(Fixed const & tmp) const;
	Fixed & operator*(Fixed const & tmp) const;
	Fixed & operator/(Fixed const & tmp) const;
	
	Fixed & operator++(void);
	Fixed const operator++(int);
	Fixed & operator--(void);
	Fixed const operator--(int);

	bool operator>(Fixed const & tmp);
	bool operator<(Fixed const & tmp);
	bool operator>=(Fixed const & tmp);
	bool operator<=(Fixed const & tmp);
	bool operator==(Fixed const & tmp);
	bool operator!=(Fixed const & tmp);

	static Fixed & min(Fixed & f1, Fixed & f2);
	static Fixed const & min(Fixed const & f1, Fixed const & f2);
	static Fixed & max(Fixed & f1, Fixed & f2);
	static Fixed const & max(Fixed const & f1, Fixed const & f2);

private:
	int _val;
	static int const _frBits;
	
};

std::ostream & operator<<(std::ostream & os, Fixed const & tmp); 

#endif
