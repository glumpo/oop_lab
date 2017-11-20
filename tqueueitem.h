#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H
#include "figure.h"
#include <memory>

template <class T>
class TQueueItem
{
public:
    TQueueItem(T *var_p);
    virtual ~TQueueItem();

    std::shared_ptr<TQueueItem> next;
    std::shared_ptr<T> var_sp;
};

#endif // TQUEUEITEM_H
