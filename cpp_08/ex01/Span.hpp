#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <map>

class Span
{
private:
	unsigned int n;
	unsigned int size;
	int *arr;
	Span();
public:
	Span(unsigned int n);
	Span(const Span &copy);
	~Span();
	Span &operator=(const Span &copy);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
	class FullArrayException : public std::exception
	{
		const char *what() const throw()
		{
			return ("Error: Array is full");
		}
	};

	template<typename T>
	void addNumber(const typename T::iterator &begin, const typename T::iterator &end)
	{
		if (size + std::distance(begin, end) > n)
			throw FullArrayException();
		for (typename T::iterator it = begin; it != end; it++)
			arr[size++] = *it;
	}

	class NoSpanException : public std::exception
	{
		const char *what() const throw()
		{
			return ("Error: No Span to find");
		}
	};
};

#endif