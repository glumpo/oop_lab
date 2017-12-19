#include "tcollection_real.h"

TCollection::TCollection() {
    this->num_for_tree = 0;
}

void TCollection::push(Figure fig) {
    if (this->body.is_empthy() || this->body.get()->get_num_of_els() >= 5) {
        this->body.push(new TBinTree<int, Figure>());
        this->body.get()->add(num_for_tree, fig);
        ++num_for_tree;
    }
}
