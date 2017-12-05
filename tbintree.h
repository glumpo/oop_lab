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
    bool add(Key key, Value *val) {
        std::shared_ptr< TBinTreeItem<Key, Value> > *cur;
        cur = &(this->root);
        while (cur->get()) {
            Key cur_key = (*cur)->key;
            const int who_is_bigger = this->cmp(key, cur_key);
            if (1 == who_is_bigger) {
                cur = &((*cur)->l);
            }
            else if (-1 == who_is_bigger) {
                cur = &((*cur)->r);
            }
            else {
                return false;
            }
        }

        TBinTreeItem<Key, Value> *tmp;
        tmp = new TBinTreeItem<Key, Value>(key, val);
        cur->reset(tmp);
        tmp->var_sp->print_info();
        return true;
    }

    std::shared_ptr<Value> get(Key key) {
        auto cur = this->root;
        while (cur.get()) {
            Key cur_key = cur->key;
            const int who_is_bigger = this->cmp(key, cur_key);
            if (1 == who_is_bigger) {
                cur = cur->l;
            }
            else if (-1 == who_is_bigger) {
                cur = cur->r;
            }
            else {
                break;  // found
            }
        }
        if (cur.get())
            return cur->var_sp;
        else {
            std::shared_ptr<Value> empty;
            return empty;
        }
    }
};

#endif // TBINTREE_H
