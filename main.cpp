 // 27

#include <iostream>

#include "coordinates.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"

#include "tqueue.h"
#include "titerator.h"

#include "tbintree.h"
#include "tallocblock.h"

#include "tcollection.h"

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

//    TQueue<Rectangle> q;

//    q.push(new Rectangle(list, 4));
//    q.push(new Rectangle(list2, 4));
//    q.push(new Rectangle(list2, 4));

    // t.pop_sp().get()->print_info();

//    for (TIterator<TQueueItem<Rectangle>, Rectangle> i = q.begin();
//         i != q.end();
//         ++i) {
//        i->print_info();
//    }

//    for (auto i : q) {
//        i->print_info();
//    }

//    TBinTree<int, Rectangle*> tree;
//    tree.add(3, new Rectangle(list, 4));
//    tree.add(4, new Rectangle(list2, 4));
//    tree.add(2, new Rectangle(list, 4));

//    bool *suc_p, suc = true;
//    suc_p = &suc;
//    tree.pop(3, suc_p)->print_info();
//    tree.pop(4, suc_p)->print_info();
//    tree.pop(2, suc_p)->print_info();

//    TAllocBlock<Rectangle> alloc = TAllocBlock<Rectangle>(10);
//    auto p1 = alloc.alloc();
//    new (p1) Rectangle(list2, 4);
//    p1->print_info();
//    alloc.dealloc(p1);

//    auto p = new Rectangle(list, 4);
//    p->print_info();
//    delete p;

    TCollection c;
    c.push(new Rectangle(list, 4));
//    c.push(new Rectangle(list, 4));
//    c.push(new Rectangle(list, 4));
    c.print_all();

    return 0;
}
