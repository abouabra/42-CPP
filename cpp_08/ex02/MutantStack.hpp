#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>()
		{
		}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy)
		{
		}
		~MutantStack() 
		{
		}
		MutantStack& operator=(const MutantStack &copy) 
		{
			if (this != copy)
				this->c = copy.c;
			return (*this);
		}

		typedef  typename std::stack<T>::container_type container;
		
		typedef typename container::iterator					iterator;
		typedef typename container::const_iterator				const_iterator;

		typedef typename container::reverse_iterator			reverse_iterator;
		typedef typename container::const_reverse_iterator		const_reverse_iterator;

		iterator       begin()
		{
			return (this->c.begin());
		}
		iterator       end()
		{
			return (this->c.end());
		}

		reverse_iterator       rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator       rend()
		{
			return (this->c.rend());
		}

		const_iterator         cbegin()
		{
			return (this->c.cbegin());
		}
		const_iterator         cend()
		{
			return (this->c.cend());
		}

		const_reverse_iterator crbegin()
		{
			return (this->c.crbegin());
		}
		const_reverse_iterator crend()
		{
			return (this->c.crend());
		}
};

#endif