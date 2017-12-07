#ifndef TBINTREE_CPP
#define TBINTREE_CPP

#include "tbintree_real.h"

template<class Key, class Value>
bool TBinTree<Key, Value>::add(Key key, Value val) {
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
Value TBinTree<Key, Value>::pop(Key key) {
    bool suc = true;
    bool *suc_p = &suc;
    return pop(key, suc_p);
}

template<class Key, class Value>
Value TBinTree<Key, Value>::pop(Key key, bool *sucsess) {
    *sucsess = true;
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
        *sucsess = false;
        Value empty;
        return empty;
    }

    Value res = (*cur)->var;
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
    (*cur)->var = (*tmp)->var;
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

template<class Key, class Value>
bool TBinTree<Key, Value>::find_first_key_by_value(const Value &patern, Key *res) {
    return _find_first_key_by_value(patern, this->root, res);
}

template<class Key, class Value>
bool TBinTree<Key, Value>::_find_first_key_by_value(const Value &patern,
                                           const std::shared_ptr<TBinTreeItem<Key, Value> > cur,
                                           Key *res) {
    if (!cur.get()) {
        return false;
    }

    if (patern == cur->var) {
        *res = cur->key;
        return true;
    }

    if (cur->r.get()) {
        if (_find_first_key_by_value(patern, cur->r, res))
            return true;
    }
    if (cur->l.get()) {
        if (_find_first_key_by_value(patern, cur->l, res))
            return true;
    }
    return false;
}



#endif // TBINTREE_CPP
