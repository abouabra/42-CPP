#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->fixed = obj.fixed;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed:: getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed = raw;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed = num * (1 << this->bits);
}
Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;

    this->fixed = roundf(num * (1 << this->bits));
}

int Fixed::toInt( void ) const
{
    int ret;

    ret = this->fixed / (1 << this->bits);
    return ret;
}

float Fixed::toFloat( void ) const
{
    float ret;

    ret = (float)this->fixed / (1 << this->bits);
    return ret;
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
