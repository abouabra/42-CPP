#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(Fixed x, Fixed y);
    Point(const Point &instance);
    Point& operator=(const Point &instance);
    ~Point();
    
    Fixed get_X() const;
    Fixed get_Y() const;
};

std::ostream &operator << (std::ostream &out, const Point &point);


bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif