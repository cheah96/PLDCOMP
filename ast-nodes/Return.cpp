#include "Return.h"

string Return::buildIR(CFG * cfg){
    /*string var = expr->buildIR(cfg);
    Type typeInt("int");
    vector<string> params;
    params.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ret,typeInt,params);*/
	Type returnType = cfg->get_var_type("retValue");
	if(returnType.getText() == "void"){
		if(expr != nullptr){
			cerr << "Erreur dans le retour void" << endl;
		}
	}else{
	    string value= expr->buildIR(cfg);
		if(expr != nullptr && returnType.getText() == expr->getType().getText()){
			string left = cfg->create_new_tempvar(expr->getType());
			int offset= cfg->get_var_index("retValue");
			vector<string>params1={left,"-"+to_string(-offset)};
			cfg->current_bb->add_IRInstr(IRInstr::ldconst,expr->getType(),params1);
			vector<string>params2={left,"!bp",left};
			cfg->current_bb->add_IRInstr(IRInstr::add,expr->getType(),params2);
			vector<string> params3={left,value};
			cfg->current_bb->add_IRInstr(IRInstr::wmem,expr->getType(),params3);
		}else{
		    cerr << returnType.getText() << endl;
		    cerr << expr->getType().getText() << endl;
			cerr << "Erreur du type de retour ou sans expression" << endl;
		}
	}
    return "";
}
