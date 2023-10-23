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
			if (this == &copy)
				return (*this);
			std::stack<T>::operator=(copy);
			return (*this);
		}

		typedef  typename std::stack<T>::container_type container;
		
		typedef typename container::iterator					iterator;
		typedef typename container::const_iterator				const_iterator;

		typedef typename container::reverse_iterator			reverse_iterator;
		typedef typename container::const_reverse_iterator		const_reverse_iterator;

		iterator       begin()
		{
			return (std::stack<T>::c.begin());
		}
		iterator       end()
		{
			return (std::stack<T>::c.end());
		}

		reverse_iterator       rbegin()
		{
			return (std::stack<T>::c.rbegin());
		}
		reverse_iterator       rend()
		{
			return (std::stack<T>::c.rend());
		}

		const_iterator         cbegin()
		{
			return (std::stack<T>::c.cbegin());
		}
		const_iterator         cend()
		{
			return (std::stack<T>::c.cend());
		}

		const_reverse_iterator crbegin()
		{
			return (std::stack<T>::c.crbegin());
		}
		const_reverse_iterator crend()
		{
			return (std::stack<T>::c.crend());
		}
};

#endif