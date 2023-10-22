#include "Span.hpp"

Span::Span(unsigned int n) : n(n), size(0)
{
    arr = new int[n];
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span::~Span()
{
    delete[] arr;
}
Span& Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        n = copy.n;
        size = copy.size;
        delete[] arr;
        arr = new int[n];
        for (unsigned int i = 0; i < size; i++)
            arr[i] = copy.arr[i];
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (size == this->n)
        throw FullArrayException();
    arr[size++] = n;
}


int Span::shortestSpan()
{
    if (size <= 1)
        throw NoSpanException();
    std::sort(arr, arr + size);
    int min = arr[1] - arr[0];
    for (unsigned int i = 2; i < size; i++)
    {
        if (arr[i] - arr[i - 1] < min)
            min = arr[i] - arr[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (size <= 1)
        throw NoSpanException();
    std::sort(arr, arr + size);
    return arr[size - 1] - arr[0];
}