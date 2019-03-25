#include "Param.h"

Param::~Param(){
    size_t length = myExprs.size();
    for(size_t i = 0; i < length; i++){
        delete myExprs[i];
    }
    myExprs.clear();
}

vector<string> Param::buildIR(CFG* cfg){
    vector<string> params;
    for(Expr* e : myExprs){
        string var = e->buildIR(cfg);
        params.push_back(var);
    }
    return params;
}