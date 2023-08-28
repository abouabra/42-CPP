#include "Point.hpp"
#include "Fixed.hpp"

Point::Point():x(Fixed()), y(Fixed())
{
    std::cout << "Default constructor called" << std::endl;
}
Point::Point(Fixed X, Fixed Y):x(X), y(Y)
{

}

Point::Point(const Point &obj)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Point& Point::operator=(const Point &obj)
{
    (void) obj;
    return *this;
}

Point::~Point()
{
    // std::cout << "Destructor called" << std::endl;
}

std::ostream &operator << (std::ostream &out, const Point &point)
{
    out << "X: " << point.get_X() << " Y: "  << point.get_Y();
    return out;
}

Fixed Point::get_X() const
{
    return this->x;
}

Fixed Point::get_Y() const
{
    return this->y;
}