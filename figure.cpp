#include "figure.h"
#include "coordinates.h"
#include <iostream>


#define N_OF_BLOCKS_TO_ALLOCATE 10

TAllocBlock<Figure> Figure::alloc(N_OF_BLOCKS_TO_ALLOCATE);


Figure::Figure() {
    this->len_of_list = 1;
    this->list = new coordinates[this->len_of_list];
    this->list->x = 0;
    this->list->y = 0;
}

Figure::Figure(const coordinates *list, int num_of_points) {
    this->len_of_list = num_of_points;
    this->list = new coordinates[num_of_points];
    for (int i = 0; i < num_of_points; ++i) {
        this->list[i] =list[i];
    }
}

Figure::Figure(std::istream &is) {
    std::cout << "Enter Number Of Points: ";
    is >> this->len_of_list;
    this->list = new coordinates[this->len_of_list];

    std::cout << "Enter Points:\n";
    for (int i = 0; i < this->len_of_list; ++i) {
        is >> this->list[i];
    }
}

Figure::Figure(int code) {
    this->list = nullptr;
    this->len_of_list = 0;
}

Figure::Figure(const Figure &obj) {
    this->len_of_list = obj.len_of_list;
    this->list = new coordinates[this->len_of_list];
    for (int i = 0; i < this->len_of_list; ++i) {
        this->list[i] = obj.list[i];
    }
}

Figure::~Figure() {
    if (this->list != nullptr) {
        delete [] this->list;
        this->list = nullptr;
    }
}

double Figure::calculate_square_gauss() {
    if (this->len_of_list <= 0) {
        return this->len_of_list;
    }

    double s1 = 0, s2 = 0, s = 0;
    auto n = this->len_of_list - 1;

    for (int i = 0; i <= n-1; ++i) {
        s1 += this->list[i].x * this->list[i+1].y;
    }
    s1 += this->list[n].x * this->list[1].y;

    for (int i = 0; i <= n-1; ++i) {
        s2 += this->list[i+1].x * this->list[i].y;
    }
    s2 += this->list[1].x * this->list[n].y;

    s = (s1 > s2) ? (s1 - s2) : (s2 - s1);
    return s; // why not /2 ???
}

void Figure::print_info(std::ostream &os) const {
    if (this->len_of_list <= 0) {
        os << "CURREPTED OBJECT: " << this->len_of_list;
        return;
    }
    this->print_figure_name();

    char curent_ch = 'A';
    for (int i = 0; i < this->len_of_list; ++i) {
        os << curent_ch++ << ": (" << this->list[i].x << ";"
                  << this->list[i].y << ")\n";
    }

    os << std::endl;

    curent_ch = 'A';
    for (int i = 1; i < this->len_of_list; ++i) {
        os << curent_ch;
        os << ++curent_ch;
        os << ": " << distance(this->list[i-1], this->list[i]);
        os << std::endl;
    }
    os << curent_ch << "A: ";
    os << distance(this->list[this->len_of_list-1], this->list[0]);
    os << std::endl;

    os << "S = " << calculate_square() << std::endl;
}

void *Figure::operator new(size_t size) {
    return alloc.alloc();
}

void Figure::operator delete(void *p) {
    alloc.dealloc(static_cast<Figure*>(p));
}

Figure& Figure::operator =(Figure &right) {
    // check if it`s right = right
    if (this == &right) {
        return *this;
    }

    this->len_of_list = right.len_of_list;
    this->list = new coordinates[this->len_of_list];
    for (int i = 0; i < this->len_of_list; ++i) {
        this->list[i] = (right.list)[i];
    }
    return *this;
}

void Figure::print_info() const {
    print_info(std::cout);
}

std::ostream &operator <<(std::ostream &os, Figure &fig) {
    fig.print_info(os);
    return os;
}
