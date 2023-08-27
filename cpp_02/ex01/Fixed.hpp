#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
private:
    int fixed;
    const static int bits = 8;
public:
    Fixed();
    Fixed(const Fixed &instance);
    Fixed& operator=(const Fixed &instance);
    ~Fixed();

    Fixed(const int num);
    Fixed(const float num);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    
    float toFloat( void ) const;
    int toInt( void ) const;

};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif