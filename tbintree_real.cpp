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

    this->num_of_els += 1;
    return true;
}


template<class Key, class Value>
Value TBinTree<Key, Value>::pop(Key key) {
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
        throw std::range_error("Key not found");
        Value empty;
        return empty;
    }

    this->num_of_els -= 1;
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
Value TBinTree<Key, Value>::get(Key key) {
    auto res = pop(key);
    add(key, res);
    return res;
}

template<class Key, class Value>
TQueue<TBinTreeItem<Key, Value>> TBinTree<Key, Value>::get_items_queue() const {
    TQueue<TBinTreeItem<Key, Value>> res;
    if (is_empty())
        return res;
    return get_items_queue(this->root, res);
}

template<class Key, class Value>
TQueue<TBinTreeItem<Key, Value>> TBinTree<Key, Value>::get_items_queue(std::shared_ptr< TBinTreeItem<Key, Value> > cur,
                                                 TQueue<TBinTreeItem<Key, Value>> &q) const {
    if (cur->l.get())
        get_items_queue(cur->l, q);
    if (cur->r.get())
        get_items_queue(cur->r, q);
    q.push(cur.get());
    return q;
}


template<class Key, class Value>
unsigned int TBinTree<Key, Value>::get_num_of_els() const {
    return this->num_of_els;
}

template<class Key, class Value>
Key TBinTree<Key, Value>::max_key() {
    auto cur = this->root;
    while (cur->r.get())
        cur = cur->r;
    return cur->key;
}

template<class Key, class Value>
bool TBinTree<Key, Value>::key_by_value(const Value &patern, Key *res) {
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
