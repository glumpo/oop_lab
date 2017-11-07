#include "tqueueitem.h"
#include <memory>

TQueueItem::TQueueItem(Figure &var) {
    this->var_p.reset(&var);
    this->next = nullptr;
    this->prev = nullptr;
}

TQueueItem::~TQueueItem() {
    delete var_p.get();
    var_p = nullptr;
}

void TQueueItem::add_next_item(TQueueItem *item) {
    this->next = item;
    item->prev = this;
}

void TQueueItem::prev_next_item(TQueueItem *item) {
    this->prev = item;
    item->next = this;
}
