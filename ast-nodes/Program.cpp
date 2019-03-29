#include "Program.h"
#include "../gen-assembly/CFG.h"

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
        func->buildIR(cfg);
        cfgs.push_back(cfg);
    }
	return "";
}

void Program::generateCode(ofstream& o){
	o << "   .text " << endl;
	for(CFG* cfg : cfgs){
		if (cfg == nullptr) {
			continue;
		}
		cfg->gen_asm(o);
	}
}
/*void Program::addFunction(Function* func){
    funcs.push_back(func);
}*/
