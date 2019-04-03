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
	if(decParams != nullptr){
		decParams->buildIR(cfg);
	}
    block->buildIR(cfg);
    return "";
}
