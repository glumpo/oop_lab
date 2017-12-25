#include "tcollection_real.h"

TCollection::TCollection() {
    this->num_for_tree = 0;
}

void TCollection::push(Figure *fig) {
    if (this->body.is_empthy() || this->body.get()->get_num_of_els() >= 5) {
        this->body.push(new TBinTree<int, Figure*>());
    }
    this->body.get()->add(num_for_tree, fig);
    ++num_for_tree;
}

void TCollection::remove_matching(RemoveRule *rule) {
    for (auto i : this->body) {
        for (auto j : i->get_items_queue()) {
            if (rule->does_match(i->get(j->key)))
                i->pop(j->key);
        }
    }
}

void TCollection::print_all() {
    for (auto i : this->body) {
        auto items = i->get_items_queue();
        items.pop_sp()->var->print_info();
    }
}


