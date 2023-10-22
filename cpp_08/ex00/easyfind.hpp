#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Error: Element not found");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif