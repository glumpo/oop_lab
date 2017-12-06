#ifndef TBINTREE_CPP
#define TBINTREE_CPP

#include "tbintree_real.h"


template<class Key, class Value>
bool TBinTree<Key, Value>::add(Key key, Value *val) {
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
    return true;
}

template<class Key, class Value>
std::shared_ptr<Value> TBinTree<Key, Value>::pop(Key key) {
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
            break; // found
        }
    }
    if (!cur->get()) {
        std::shared_ptr<Value> empty;
        return empty;
    }

    auto res = (*cur)->var_sp;
    if (!(*cur)->l.get() && !(*cur)->r.get()) {
        cur->reset();
        return res;
    }

    std::shared_ptr< TBinTreeItem<Key, Value> > *tmp;
    if ((*cur)->l.get()) {
        tmp = &((*cur)->l);
        while ((*tmp)->r.get()) {
            tmp = &((*tmp)->r);
        }
    }
    else {
        tmp = &((*cur)->r);
        while ((*tmp)->l.get()) {
            tmp = &((*tmp)->l);
        }
    }
    (*cur)->var_sp = (*tmp)->var_sp;
    (*cur)->key = (*tmp)->key;
    (*tmp).reset();

    return res;
}

template<class Key, class Value>
Key TBinTree<Key, Value>::max_key() {
    auto cur = this->root;
    while (cur->r.get())
        cur = cur->r;
    return cur->key;
}

#endif // TBINTREE_CPP
