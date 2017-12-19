#ifndef REMOCERULE_H
#define REMOCERULE_H
#include "figure.h"

class RemoceRule
{
public:
    virtual bool does_match(Figure *p) = 0;
};


class RemoceRuleAll : public RemoceRule
{
public:
    RemoceRuleAll() {}
    bool does_match(Figure *p) override {
        return true;
    }
};

#endif // REMOCERULE_H
