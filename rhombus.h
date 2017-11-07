#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"
#include "coordinates.h"

class Rhombus : public Figure
{
public:
    using Figure::Figure;
    double calculate_square() const override;
    void print_figure_name() const override;
    Rhombus& operator =(const Rhombus &a);
};

std::ostream& operator <<(std::ostream &os, Rhombus obj);
#endif // RHOMBUS_H
