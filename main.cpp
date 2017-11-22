// 27

#include <iostream>
#include "coordinates.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"

#include "tqueue.h"
#include "tqueue.cpp"
#include "tqueueitem.cpp"
#include "tqueueitem.h"

#include "titerator.h"

int main(int argc, char *argv[])
{
    coordinates list[4];
    list[0] = {0, 0};
    list[1] = {0, 10};
    list[2] = {10, 10};
    list[3] = {10, 0};

    coordinates list2[4];
    list2[0] = {0, 0};
    list2[1] = {5, 15};
    list2[2] = {15, 15};
    list2[3] = {20, 0};

    TQueue<Rectangle> q;

    q.push(new Rectangle(list, 4));
    q.push(new Rectangle(list2, 4));
    q.push(new Rectangle(list2, 4));

    // t.pop_sp().get()->print_info();

//    for (TIterator<TQueueItem<Rectangle>, Rectangle> i = q.begin();
//         i != q.end();
//         ++i) {
//        i->print_info();
//    }

    for (auto i : q) {
        i->print_info();
    }
    return 0;
}
