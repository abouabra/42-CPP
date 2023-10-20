#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename Arg>
void swap(Arg &a, Arg &b)
{
	Arg tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template<typename Arg>
const Arg& min(const Arg &a, const Arg &b)
{
	if(b <= a)
		return b;
	return a;
}

template<typename Arg>
const Arg& max(const Arg &a, const Arg &b)
{
	if(a > b)
		return a;
	return b;
}
#endif