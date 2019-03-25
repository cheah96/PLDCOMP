#include "Expression.h"
#include "CFG.h"

string ExprInt::buildIR(CFG * cfg){
    string var = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var);
    params.push_back(to_string(value));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
    return var;
}

string ExprVar::buildIR(CFG * cfg){
    return myName;
}

string ExprChar::buildIR(CFG * cfg){
    string var = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var);
    int valueInt = (int)value;
    params.push_back(to_string(valueInt));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
    return var;
}

string ExprBinary::buildIR(CFG * cfg){
    OPTYPE value = myOp->getValue();
    string var1 = op1->buildIR(cfg);
    string var2 = op2->buildIR(cfg);
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    switch(value){
        case ADD:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params);
            break;
        case SUB:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),params);
            break;
        case MULT:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::mul,this->getType(),params);
            break;
        case DIV:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::div,this->getType(),params);
            break;   
    }
    return var3;
}
