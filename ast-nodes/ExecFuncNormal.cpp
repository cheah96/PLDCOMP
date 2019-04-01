#include "ExecFuncNormal.h"
#include "Program.h"

ExecFuncNormal::~ExecFuncNormal(){
    delete myParams;
}

string ExecFuncNormal::buildIR(CFG* cfg){
	Type* myType = cfg->prog->getFuncReturn(funcName);
	string right = cfg->create_new_tempvar(*myType);
	vector<string> funcParams = myParams->buildIR(cfg);
        vector<string> params;
        params.push_back(right);
        params.push_back(funcName);
        for(string s : funcParams){
		params.push_back(s);
        }
        cfg->current_bb->add_IRInstr(IRInstr::call,*myType,params);
	return right;
}
