#include "tqueueitem.h"
#include <memory>

TQueueItem::TQueueItem(Figure *var_p) {
    this->var_sp.reset(var_p);
}

TQueueItem::~TQueueItem() {
}
