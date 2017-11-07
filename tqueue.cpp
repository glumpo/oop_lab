#include "tqueue.h"

TQueue::TQueue() {
    this->head = nullptr;
}

TQueue::~TQueue() {
    auto cur = this->head;
    while (cur) {
        auto tmp = cur;
        delete cur;
        cur = tmp;
    }
}

std::shared_ptr<Figure> TQueue::pop_sp() {
    if (nullptr == this->head->next) {
        auto res1 = this->head->var_p;
        // delete this->head;
        this->head = nullptr;
        return res1;
    }

    auto cur = this->head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    auto prev = cur->prev;
    auto res = cur->var_p;
    if (nullptr != cur) {
       // delete cur;
        cur = nullptr;
     }
    prev->next = nullptr;
    return res;
}

void TQueue::push(Figure &val) {
    TQueueItem *res = new TQueueItem(val);
    if (nullptr == this->head) {
        this->head = res;
        this->head->next = nullptr;
        this->head->prev = nullptr;
    }
    else {
        res->next = this->head;
        res->next->prev = res;
        res->prev = nullptr;
        this->head = res;
    }
}

bool TQueue::is_empthy() {
    if (nullptr == this->head)
        return true;
    return false;
}


