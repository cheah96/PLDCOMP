#include "Expression.h"

string ExprInt::buildIR(CFG * cfg){
    /*string var = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var);
    params.push_back(to_string(value));
    cfg->current_bb->add_IRInstr(ldconst,this->getType(),);
    return var;*/
    return "";
}

string ExprVar::buildIR(CFG * cfg){
    return myName;
}

string ExprBinary::buildIR(CFG * cfg){
    /*OPTYPE value = myOp->getValue();
    string var1 = op1->buildIR(cfg);
    string var2 = op2->buildIR(cfg);
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    switch(value){
        case ADD:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            //IRinstr* tempInstr = new AddIntsr(cfg->current_bb,var3,var1,var2);
            cfg->current_bb->add_IRInstr(add,this->getType(),params);
            break;
        case SUB:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            //IRinstr* tempInstr = new AddIntsr(cfg->current_bb,var3,var1,var2);
            cfg->current_bb->add_IRInstr(sub,this->getType(),params);
            break;
        case MULT:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            //IRinstr* tempInstr = new AddIntsr(cfg->current_bb,var3,var1,var2);
            cfg->current_bb->add_IRInstr(mul,this->getType(),params);
            break;
        case DIV:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            //IRinstr* tempInstr = new AddIntsr(cfg->current_bb,var3,var1,var2);
            cfg->current_bb->add_IRInstr(div,this->getType,params);
            break;   
    }
    return var3;*/
    return "";
}