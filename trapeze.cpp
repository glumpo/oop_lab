#include "trapeze.h"
#include "coordinates.h"
#include <tgmath.h>

double Trapeze::calculate_square() const {
    // by 4 sides
    double a, b, c, d;
    a = distance(this->list[0], this->list[1]);
    b = distance(this->list[1], this->list[2]);
    c = distance(this->list[2], this->list[3]);
    d = distance(this->list[3], this->list[4]);

    double tmp = (pow(b-a, 2) + c*c - d*d) / (2 * (b-a));
    double s = (a+b) * sqrt(c*c - tmp*tmp) / 2;
    return s;
}

void Trapeze::print_figure_name() const {
    std::cout << "Trapeze\n";
}

Trapeze &Trapeze::operator =(const Trapeze &a) {
    if (this == &a)
        return *this;

    this->len_of_list = a.len_of_list;
    if (this->list != nullptr) {
        delete [] this->list;
    }
    this->list = new coordinates[this->len_of_list];

    for (int i = 0; i < this->len_of_list; ++i) {
        this->list[i] = a.list[i];
    }
    return *this;
}

std::ostream& operator <<(std::ostream &os, Trapeze obj) {
    obj.print_info();
    return os;
}
