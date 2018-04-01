#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
private:
	T *_arr;
	unsigned int _size;
public:
	Array<T>(void)
	{
		this->_arr = new T[0];
		this->_size = 0;
	}
	Array<T>(unsigned int n)
	{
		this->_arr = new T[n];
		this->_size = n;
	}
	Array<T>(Array<T> & rhs)
	{
		*this = rhs;
	}
	~Array<T>() { delete this->_arr; }
	
	T & operator[](unsigned int n) const
	{
		if (n >= this->_size)
			throw Array<T>::NonexistException();
		return (this->_arr[n]);
	}

	Array<T> & operator=(Array<T> const & rhs)
	{
		this->_arr = new T[rhs.size()];
		this->_size = rhs.size();
		for (unsigned int i = 0; i < this->_size; ++i)
		{
			this->_arr[i] = rhs[i];
		}
		return (*this);
	}

	unsigned int size(void) const { return (this->_size); }

	class NonexistException : public std::exception
	{
	public:
		NonexistException(void) {}

		char const * what() const throw()
		{
			return ("Non exist element of array");
		}
	};
};

#endif
