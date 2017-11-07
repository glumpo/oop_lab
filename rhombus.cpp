#include "rhombus.h"


double Rhombus::calculate_square() const {
    double h = distance(this->list[0], this->list[2]);
    double l = distance(this->list[1], this->list[3]);
    return l*h / 2;
}

void Rhombus::print_figure_name() const {
    std::cout << "Rhombus\n";
}

Rhombus &Rhombus::operator =(const Rhombus &a) {
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

std::ostream& operator <<(std::ostream &os, Rhombus obj) {
    obj.print_info();
    return os;
}
