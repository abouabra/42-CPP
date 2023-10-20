#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(const T &str)
{
    std::cout << str << std::endl;
}
template <typename T>
void iter(const T *arr,size_t len, void(*f)(const T&))
{
	for(size_t i = 0;i < len; i++)
		f(arr[i]);
}
#endif