#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H
#include "figure.h"
#include <memory>
class TQueueItem
{
public:
    TQueueItem(Figure &var);
    virtual ~TQueueItem();
    // Resource Acquision Is Initialization

    void add_next_item(TQueueItem *item);
    void prev_next_item(TQueueItem *item);

    TQueueItem *next;
    TQueueItem *prev;
    std::shared_ptr<Figure> var_p;
};

#endif // TQUEUEITEM_H
