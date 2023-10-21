#include "iter.hpp"
#include <string>

int main( void )
{
    size_t len  = 5;

    std::string str_arr[len];
    int int_arr[len];
    float float_arr[len];

    for(size_t i = 0;i < len; i++)
    {
        str_arr[i] = "Hello world!";
        int_arr[i] = i;
        float_arr[i] = i + i / 10.0f;
    }

    iter(str_arr, len, &print);
    std::cout << std::endl;
    iter(int_arr, len, &print);
    std::cout << std::endl;
    iter(float_arr, len, &print);

    return 0;
}