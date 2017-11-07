#ifndef TQUEUE_H
#define TQUEUE_H
#include "tqueueitem.h"
#include "figure.h"

class TQueue
{
private:
    void del_queue_helper(std::shared_ptr<TQueueItem> el);
    size_t size;
protected:
    std::shared_ptr<TQueueItem> bottom;
public:
    TQueue();
    ~TQueue();

    std::shared_ptr<Figure> pop_sp();
    void push(Figure *val);
    bool is_empthy();
};

#endif // TQUEUE_H
