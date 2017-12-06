#ifndef TBINTREE_H
#define TBINTREE_H

#include "tbintreeitem.h"
#include <memory>


/*
 * Equal keys not allowed
 */
template <class Key, class Value>
class TBinTree
{
private:
    std::shared_ptr< TBinTreeItem<Key, Value> > root;

    /*
     * 1 : inp < orig;
     * -1: inp > orig;
     * 0 : inp == orig;
     */
    int (*cmp)(const Key inp, const Key orig);
public:
    TBinTree() : cmp([](const Key inp, const Key orig) {
        if (inp < orig)
            return 1;
        if (inp > orig)
            return -1;
        else
            return 0;
    }) {this->root.reset();}
    TBinTree(int (*comparator)(Key inp, Key orig)) : cmp(comparator) {this->root.reset();}

    // TODO: Code Duplication in add and get
    bool add(Key key, Value *val);
    std::shared_ptr<Value> pop(Key key);
    Key max_key();
};

#endif // TBINTREE_H
