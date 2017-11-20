#ifndef TQUEUE_H
#define TQUEUE_H
#include "tqueueitem.h"
#include "figure.h"


template <class T>
class TQueue
{
private:
    void del_queue_helper(std::shared_ptr<TQueueItem<T>> el);
    size_t size;
protected:
    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> bottom;
public:
    TQueue();
    ~TQueue();

    std::shared_ptr<T> pop_sp();
    void push(T *val);
    bool is_empthy();
};

#endif // TQUEUE_H
