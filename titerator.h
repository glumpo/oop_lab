#ifndef TITERATOR_H
#define TITERATOR_H

#include <memory>

template <class node, class T>
class TIterator
{
public:
    TIterator(std::shared_ptr<node> n) {
        this->curent_ptr = n;
    }
    virtual ~TIterator() {}

    // TODO: delete code duplication on * and ->
    // TODO: change var_sp on get_element();
    std::shared_ptr<T> operator *() {
        return this->curent_ptr->var_sp;
    }

    // TODO: change var_sp on get_element();
    std::shared_ptr<T> operator ->() {
        return this->curent_ptr->var_sp;
    }

    // TODO: change next on get_next();
    void step_forward() {
        curent_ptr = curent_ptr->next;
    }
    TIterator operator ++() {
        step_forward();
        return *this;
    }
    TIterator operator ++(int) {
        auto cur = *this;
        this->step_forward();
        return cur;
    }

    bool operator ==(TIterator r) {
        return this->curent_ptr == r.curent_ptr;
    }
    bool operator !=(TIterator r) {
        return !(*this == r);
    }



private:
    std::shared_ptr<node> curent_ptr;
};

#endif // TITERATOR_H
