#include "DefVar.h"

string DefVarWithDeclar::buildIR(CFG * cfg){

    cout << "defVar" << endl;
    //Declaration
    string left = myVar->buildIR(cfg);
    cfg->add_to_symbol_table(left,*myType);
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Get the address of the variable
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    cout << "finDefVar" << endl;
    return right;
}

string DefVarWithoutDeclar::buildIR(CFG * cfg){
     cout << "DefVarWithoutDeclar" << endl;
    //Declaration
    string left = myVar->buildIR(cfg);
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Get the address of the variable
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    cout << "finDefVarWithoutDeclar" << endl;
    return right;
}
