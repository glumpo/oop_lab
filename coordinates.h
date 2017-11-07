#ifndef COORDINATES_H
#define COORDINATES_H
#include <iostream>

struct coordinates {
    double x, y;
};

std::istream& operator >>(std::istream &is, coordinates &c);
double distance(const coordinates a, const coordinates b);

#endif // COORDINATES_H
