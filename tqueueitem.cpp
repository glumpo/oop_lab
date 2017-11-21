#include "tqueueitem.h"
#include <memory>

#ifndef TQUEUEITEM_CPP
#define TQUEUEITEM_CPP

template <class T>
TQueueItem<T>::TQueueItem(T *var_p) {
    this->var_sp.reset(var_p);
}

template <class T>
TQueueItem<T>::~TQueueItem() {}


#endif  //TQUEUEITEM_CPP
