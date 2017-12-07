#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

#include <iostream>

class Rectangle : public Figure
{
public:
    using Figure::Figure;
    Rectangle();
    virtual ~Rectangle() {std::cout << "REC DIE!!" << std::endl;}
    double calculate_square() const override;
    void print_figure_name() const override;

    Rectangle& operator =(const Rectangle& a);
};

std::ostream& operator <<(std::ostream &os, Rectangle &obj);

#endif // RECTANGLE_H
