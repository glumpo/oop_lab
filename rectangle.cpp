#include "rectangle.h"

Rectangle::Rectangle() {
    this->len_of_list = 4;
    this->list = new coordinates[4];
}

double Rectangle::calculate_square() const {
    double h = distance(this->list[0], this->list[1]);
    double l = distance(this->list[1], this->list[2]);
    return h*l;
}

void Rectangle::print_figure_name() const {
    std::cout << "Rectangle\n";
}

Rectangle &Rectangle::operator =(const Rectangle &a) {
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

std::ostream& operator <<(std::ostream &os, Rectangle &obj) {
    obj.print_info(os);
    return os;
}
