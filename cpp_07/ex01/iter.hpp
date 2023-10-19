#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <sys/_types/_size_t.h>

template <typename T>
void print(T &str)
{
    std::cout << str << std::endl;
}
template <typename T>
void iter(T *arr,size_t len, void(*f)(T&))
{
	for(size_t i = 0;i < len; i++)
		f(arr[i]);
}
#endif