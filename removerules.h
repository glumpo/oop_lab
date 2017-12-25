#ifndef REMOCERULE_H
#define REMOCERULE_H
#include "figure.h"

class RemoveRule
{
public:
    virtual bool does_match(Figure *p) = 0;
};


class RemoveRuleAll : public RemoveRule
{
public:
    RemoveRuleAll() {}
    bool does_match(Figure *p) override {
        return true;
    }
};

#endif // REMOCERULE_H
