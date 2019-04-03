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
        CFG* cfg = new CFG(func,this);
        func->buildIR(cfg);
        cfgs.push_back(cfg);
    }
	return "";
}

void Program::generateCode(ofstream& o){
	o << "   .text " << endl;
	for(CFG* cfg : cfgs){
	    cout << cfg->ast->getName() << endl;
		if (cfg == nullptr) {
			continue;
		}
		cfg->gen_asm(o);
	}
}

Type* Program::getFuncReturn(string name){
	Type* returnType = nullptr;
	for(Function* func : funcs){
		if(func->getName() == name){
			returnType = func->getReturnType();
		}
	}
	return returnType;
}
