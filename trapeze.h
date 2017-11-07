#ifndef TRAPEZE_H
#define TRAPEZE_H
#include "figure.h"

class Trapeze : public Figure
{
public:
    using Figure::Figure;
    double calculate_square() const override;
    void print_figure_name() const override;
    Trapeze& operator =(const Trapeze &a);
};

std::ostream& operator <<(std::ostream &os, Trapeze obj);
#endif // TRAPEZE_H
