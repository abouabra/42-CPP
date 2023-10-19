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
Arg& min(Arg &a, Arg &b)
{
	if(b <= a)
		return b;
	return a;
}

template<typename Arg>
Arg& max(Arg &a, Arg &b)
{
	if(a > b)
		return a;
	return b;
}
#endif