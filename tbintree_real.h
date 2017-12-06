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
    bool _find_first_key_by_value(const Value &patern, const std::shared_ptr<TBinTreeItem<Key, Value> > cur, Key *res);
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
    TBinTree(int (*comparator)(Key inp, Key orig)) : cmp(comparator) {}

    // TODO: Code Duplication in add and get
    bool add(Key key, Value val);
    Value pop(Key key);
    Value pop(Key key, bool *sucsess);

    Key max_key();
    bool find_first_key_by_value(const Value &patern, Key *res);

    bool is_empty() {
        return this->root.get() == nullptr;
    }
};

#endif // TBINTREE_H
