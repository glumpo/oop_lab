#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H
#include "figure.h"
#include <memory>
class TQueueItem
{
public:
    TQueueItem(Figure *var_p);
    virtual ~TQueueItem();

    std::shared_ptr<TQueueItem> next;
    std::shared_ptr<Figure> var_sp;
};

#endif // TQUEUEITEM_H
