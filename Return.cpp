#include "Return.h"

string Return::buildIR(CFG * cfg){
    string var = expr->buildIR(cfg);
    Type typeInt("int");
    vector<string> params;
    params.push_back(var);
    //cfg->current_bb->add_IRInstr(ret,typeInt,params);
    return "";
}