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
    Rectangle lol(list, 4);

    list[0] = {0, 0};
    list[1] = {5, 15};
    list[2] = {15, 15};
    list[3] = {20, 0};
    Rhombus kek(list, 4);
    Rectangle kek2(list, 4);

    TQueue t = TQueue();
    t.push(lol);
    t.push(kek);
    t.push(kek2);

    t.pop_sp().get()->print_info();
    t.pop_sp().get()->print_info();
    t.pop_sp().get()->print_info();
//    std::cout << kek;
    return 0;
}
