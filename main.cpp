// 27

#include <iostream>
#include "coordinates.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "tqueue.h"

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

    TQueue t = TQueue();

    t.push(new Rectangle(list, 4));
    t.push(new Rhombus(list2, 4));

    TQueue t2 = TQueue();
    TQueue t3 = TQueue();
    t2.push(new Rectangle(list, 4));
    t3.push(new Rectangle(list, 4));

    t.pop_sp().get()->print_info();
    return 0;
}
