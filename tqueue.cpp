#include "tqueue.h"

TQueue::TQueue() {
    this->size = 0;
}

void TQueue::del_queue_helper(std::shared_ptr<TQueueItem> el) {
    if ( !el.get())
        return;
    if (el->next)
        del_queue_helper(el->next);
    delete el.get();
}

TQueue::~TQueue() {
    while (!this->is_empthy())
        this->pop_sp().reset();
}

std::shared_ptr<Figure> TQueue::pop_sp() {
    std::shared_ptr<Figure> res = this->head->var_sp;
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

void TQueue::push(Figure *val) {
    if (!this->bottom.get()) {
        this->bottom.reset(new TQueueItem(val));
        this->head = this->bottom;
    }
    else {
        this->bottom->next.reset(new TQueueItem(val));
        this->bottom = this->bottom->next;
    }
    this->size += 1;
}

bool TQueue::is_empthy() {
    if (0 == this->size)
        return true;
    return false;
}


