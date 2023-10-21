#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
private:
    T *arr;
    size_t arr_size; 
public:
    Array()
    {
        arr = NULL;
        arr_size = 0;
    }
    Array(unsigned int n)
    {
        arr = new T[n];
        arr_size = n;
    }
    ~Array()
    {
        delete [] arr;
    }
    Array(const Array& obj)
    {
        arr_size = obj.arr_size;
        arr = new T[arr_size];
        for(size_t i = 0; i < arr_size; i++)
            arr[i] = obj.arr[i];
    }
    Array& operator = (Array &obj)
    {
        if(this != &obj)
        {
            delete [] arr;
            arr_size = obj.arr_size;
            arr = new T[arr_size];
            for(size_t i = 0; i < arr_size; i++)
                arr[i] = obj.arr[i];
        }
        return *this;
    }
    T& operator [] (unsigned int index)
    {
        if(index >= arr_size)
            throw OutOfRangeException();
        return arr[index];
    }
    size_t size() const
    {
        return arr_size;
    }
    class OutOfRangeException: public std::exception
    {
        public:
            const char *what() const throw()
            {
                return "Error: Out Of Range";
            }
    };
};

#endif