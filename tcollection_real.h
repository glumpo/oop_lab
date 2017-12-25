#ifndef TCOLLECTION_REAL_H
#define TCOLLECTION_REAL_H

#include <memory>

#include "tbintree.h"
#include "tqueue.h"
#include "figure.h"
#include "removerules.h"

class TCollection
{
private:
    TQueue<TBinTree<int, Figure*>> body;
    int num_for_tree;
public:
    TCollection();

    void push(Figure *fig);
    // void remove(Figure *fig);
    void remove_matching(RemoveRule *rule);
    void print_all();
};

#endif // TCOLLECTION_REAL_H
