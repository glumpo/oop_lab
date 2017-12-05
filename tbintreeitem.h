#ifndef TBINTREEITEM_H
#define TBINTREEITEM_H

#include <memory>

template <class Key, class Value>
class TBinTreeItem
{
public:
    TBinTreeItem(Key key, Value *var) {
        this->var_sp.reset(var);
        this->key = key;

//        this->l.reset(nullptr);
//        this->r.reset(nullptr);
    }
    virtual ~TBinTreeItem() {}

    Key key;
    std::shared_ptr<Value> var_sp;
    std::shared_ptr< TBinTreeItem<Key, Value> > r;
    std::shared_ptr< TBinTreeItem<Key, Value> > l;
};

#endif // TBINTREEITEM_H
