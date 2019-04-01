#include "PutChar.h"

PutChar::~PutChar(){
    delete myExpr;
}

string PutChar::buildIR(CFG* cfg){
	vector<string> params;
	params.push_back("");
	params.push_back(funcName);
	string var = myExpr->buildIR(cfg);
	params.push_back(var);
	Type typeChar("char");
	cfg->current_bb->add_IRInstr(IRInstr::call,typeChar,params);
    return "";
}
