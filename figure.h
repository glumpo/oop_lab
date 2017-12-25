#ifndef FIGURE_H
#define FIGURE_H
#include "coordinates.h"
#include "tallocblock.h"

#include <iostream>

class Figure
{
protected:
    int len_of_list;
    coordinates *list;
    // static TAllocBlock<Figure> alloc;
public:
    Figure(const coordinates *list, int len_of_list);
    Figure(std::istream &is);
    Figure(int code);
    Figure(const Figure &obj);
    Figure();

    virtual Figure& operator =(Figure &right);

    virtual ~Figure();

    double calculate_square_gauss();
    virtual double calculate_square() const = 0;
    virtual void print_figure_name() const = 0;
    void print_info() const;
    void print_info(std::ostream &os) const;

//     void *operator new(size_t size);
//     void operator delete(void *p);
};

std::ostream &operator <<(std::ostream &os, Figure &fig);


#endif // FIGURE_H
