#include "ParamDec.h"

ParamDec::~ParamDec(){
	size_t length = myDecs.size();
	for(size_t i = 0; i < length; i++){
	delete myDecs[i];
	}
	myDecs.clear();
}

string ParamDec::buildIR(CFG* cfg){
	for(size_t i = 0; i < myDecs.size(); i++){
		cfg->add_to_symbol_table(myDecs[i]->getName(),*(myDecs[i]->getType()));
	}
	return "";
}
