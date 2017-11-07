#include "tqueue.h"

TQueue::TQueue() {
    this->size = 0;
}

void TQueue::del_queue_helper(std::shared_ptr<TQueueItem> el) {
    if ( el.get())
        return;
    if (el->next)
        del_queue_helper(el->next);
    delete el.get();
}

TQueue::~TQueue() {
    if ( (this->bottom).get() )
        del_queue_helper(this->bottom);
    this->size = 0;
}

std::shared_ptr<Figure> TQueue::pop_sp() {
    std::shared_ptr<TQueueItem> cur = this->bottom;
    for (auto i = 1; i < this->size; ++i) {
        cur = cur->next;
    }
    this->size -= 1;
    std::shared_ptr<Figure> res = cur.get()->var_sp;
    cur.reset();
    return res;
}

void TQueue::push(Figure *val) {
    this->size += 1;
    if ( !(this->bottom).get() ) {
        this->bottom.reset(new TQueueItem(val));
        return;
    }

    std::shared_ptr<TQueueItem> cur = this->bottom;
    while ( (cur->next).get() ) {
        cur = cur->next;
    }
    cur->next.reset(new TQueueItem(val));
}

bool TQueue::is_empthy() {
    if (0 == this->size)
        return true;
    return false;
}


