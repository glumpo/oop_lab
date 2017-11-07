#ifndef TQUEUE_H
#define TQUEUE_H
#include "tqueueitem.h"
#include "figure.h"

class TQueue
{
private:
    TQueueItem *head;
public:
    TQueue();
    ~TQueue();

    std::shared_ptr<Figure> pop_sp();
    void push(Figure &val);
    bool is_empthy();
};

#endif // TQUEUE_H
