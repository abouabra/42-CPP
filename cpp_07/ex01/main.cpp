#include "iter.hpp"
#include <string>

int main( void )
{
    size_t len  = 10;
    std::string arr[len];
    for(size_t i = 0;i < len; i++)
    {
        arr[i] = "Hello: " + std::to_string(i);
        // arr[i] = i;
        // arr[i] = i + i / 10.0f;

    }
    iter(arr, len, &print);

    return 0;
}