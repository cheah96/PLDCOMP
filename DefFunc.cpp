#include "DefFunc.h"

DefFunc::~DefFunc() { 
    size_t length = params.size();
    for(size_t i = 0; i < length; i++){
        delete params[i];
    }
    params.clear();
    delete block;
}

void DefFunc::addParameter(Parameter* param){
    params.push_back(param);
}