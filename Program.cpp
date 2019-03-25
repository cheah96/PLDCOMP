#include "Program.h"
#include "CFG.h"

Program::Program(){
}

Program::~Program() { 
    size_t length = funcs.size();
    for(size_t i = 0; i < length; i++){
        delete funcs[i];
    }
    funcs.clear();
}

string Program::buildIR(){
    for(Function* func : funcs){
        CFG* cfg = new CFG(func);
        cout << "dqsqdqs" << endl;
        func->buildIR(cfg);
        cout << "dqs" << endl;
        cfgs.push_back(cfg);
    }
	return "";
}

void Program::generateCode(ofstream& o){
	o << "   .text " << endl;
	for(CFG* cfg : cfgs){
		if (cfg == nullptr) {
			cout << "ihofsihoqs" <<endl;
			continue;
		}
		cfg->gen_asm(o);
	}
}
/*void Program::addFunction(Function* func){
    funcs.push_back(func);
}*/
