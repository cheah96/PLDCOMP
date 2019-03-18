#include "Return.h"

string Return::buildIR(CFG * cfg){
	cout << "Return " << endl;
    string var = expr->buildIR(cfg);
    Type typeInt("int");
    vector<string> params;
    params.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ret,typeInt,params);
    cout << "finReturn " << endl;
    return "";
}
