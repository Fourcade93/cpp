#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::list<T>::iterator iterator;
	
	MutantStack<T>(void) {}

	~MutantStack<T>(void) {}
	
	void	push(T const & val)
	{
		this->_container.push_back(val);
	}

	void	pop(void)
	{
		this->_container.pop_back();
	}

	T const &	top(void)
	{
		return (this->_container.back());
	}

	unsigned int size(void) const
	{
		return (this->_container.size());
	}

	iterator begin(void)
	{
		return (this->_container.begin());
	}

	iterator end(void)
	{
		return (this->_container.end());
	}

private:
	std::list<T> _container;
};

#endif
