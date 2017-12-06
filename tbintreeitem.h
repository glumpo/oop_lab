#ifndef TBINTREEITEM_H
#define TBINTREEITEM_H

#include <memory>

template <class Key, class Value>
class TBinTreeItem
{
public:
    TBinTreeItem(Key key, Value var): var(var), key(key) {}
    virtual ~TBinTreeItem() {}

    Key key;
    Value var;
    std::shared_ptr< TBinTreeItem<Key, Value> > r;
    std::shared_ptr< TBinTreeItem<Key, Value> > l;
};

#endif // TBINTREEITEM_H
