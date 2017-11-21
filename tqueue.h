#ifndef TQUEUE_H
#define TQUEUE_H
#include "tqueueitem.h"
#include "figure.h"
#include "titerator.h"


template <class T>
class TQueue
{
private:
    void del_queue_helper(std::shared_ptr<TQueueItem<T>> el);
    size_t size;
    std::shared_ptr<TQueueItem<T>> bottom;
    std::shared_ptr<TQueueItem<T>> head;
public:
    TQueue();
    ~TQueue();

    std::shared_ptr<T> pop_sp();
    void push(T *val);
    bool is_empthy();

    TIterator<TQueueItem<T>, T> begin();
    TIterator<TQueueItem<T>, T> end();
};

#endif // TQUEUE_H
