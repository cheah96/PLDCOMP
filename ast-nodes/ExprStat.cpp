#include "ExprStat.h"

ExprStat::~ExprStat() {
    delete myExpr;
}

string ExprStat::buildIR(CFG* cfg) {
    string var = myExpr->buildIR(cfg);
    return var;
}