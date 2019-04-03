#include "DefFunc.h"

DefFunc::~DefFunc() { 
    /*size_t length = params.size();
    for(size_t i = 0; i < length; i++){
        delete params[i];
    }
    params.clear();*/
    if(decParams != nullptr){
	    delete decParams;
    }
    delete block;
    delete returnType;
}

/*void DefFunc::addParameter(Parameter* param){
    params.push_back(param);
}*/

string DefFunc::buildIR(CFG* cfg){
    for(int i = 0; i < decParams->getParameters().size(); i++) {
        cfg->add_to_symbol_table(decParams->getParameters()[i]->getName(),*(decParams->getParameters()[i]->getType()));        
    }
    block->buildIR(cfg);
    return "";
}
