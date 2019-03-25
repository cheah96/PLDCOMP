#include "DeclarVar.h"

DeclarVar::~DeclarVar(){
    delete  myVars;
    delete myType;
}

string DeclarVar::buildIR(CFG* cfg){
    size_t length = myVars->size();
    for(size_t i = 0; i < length; i++){
        cfg->add_to_symbol_table(myVars->at(i),*myType);
    }
    return "";
}