#include "coordinates.h"
#include <iostream>
#include <tgmath.h>
//#define ABS(x) (x) > 0 ? (x) : -(x)

std::istream& operator >>(std::istream &is, coordinates &c) {
    // On reading from file it will spam. Tt`s not a bag, but future.
    std::cout << "X: ";
    is >> c.x;
    std::cout << "Y: ";
    is >> c.y;
    return is;
}

double distance(const coordinates a, const coordinates b) {
    double x = fabs(a.x - b.x);
    double y = fabs(a.y - b.y);
    return sqrt(x*x + y*y);
}

std::ostream &operator>>(std::ostream &os, const coordinates &c) {
    os <<"(" << c.x << ";" << c.y << ")";
    return os;
}
