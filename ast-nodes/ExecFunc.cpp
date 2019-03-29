#include "ExecFunc.h"

ExecFunc::~ExecFunc(){
    delete myParams;
}

string ExecFunc::buildIR(CFG* cfg){
    vector<string> funcParams = myParams->buildIR(cfg);
    if(funcName == "putchar"){
        vector<string> params;
        params.push_back("");
        params.push_back(funcName);
        for(string s : funcParams){
            params.push_back(s);
        }
        Type typeChar("char");
        cfg->current_bb->add_IRInstr(IRInstr::call,typeChar,params);
    }else{

    }
    return "";
}