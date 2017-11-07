#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class Rectangle : public Figure
{
public:
    using Figure::Figure;
    Rectangle();
    virtual ~Rectangle() {}
    double calculate_square() const override;
    void print_figure_name() const override;

    Rectangle& operator =(const Rectangle& a);
};

std::ostream& operator <<(std::ostream &os, Rectangle &obj);

#endif // RECTANGLE_H
