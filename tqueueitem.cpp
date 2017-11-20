#include "tqueueitem.h"
#include <memory>

template <class T>
TQueueItem<T>::TQueueItem(T *var_p) {
    this->var_sp.reset(var_p);
}

template <class T>
TQueueItem<T>::~TQueueItem() {}
