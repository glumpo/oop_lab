#include "tqueue.h"

template <class T>
TQueue<T>::TQueue() {
    this->size = 0;
}

template <class T>
void TQueue<T>::del_queue_helper(std::shared_ptr< TQueueItem<T> > el) {
    if ( !el.get())
        return;
    if (el->next)
        del_queue_helper(el->next);
    delete el.get();
}

template <class T>
TQueue<T>::~TQueue() {
    while (!this->is_empthy())
        this->pop_sp().reset();
}

template <class T>
std::shared_ptr<T> TQueue<T>::pop_sp() {
    std::shared_ptr<T> res = this->head->var_sp;
    if (1 == this->size) {
        this->head.reset();
        this->bottom.reset();
    }
    else {
        this->head = this->head->next;
    }
    this->size -= 1;
    return res;
}

template <class T>
void TQueue<T>::push(T *val) {
    if (!this->bottom.get()) {
        this->bottom.reset(new TQueueItem<T>(val));
        this->head = this->bottom;
    } else {
        this->bottom->next.reset(new TQueueItem<T>(val));
        this->bottom = this->bottom->next;
    }
    this->size += 1;
}

template <class T>
bool TQueue<T>::is_empthy() {
    if (0 == this->size)
        return true;
    return false;
}


