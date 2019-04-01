#include "ParamDec.h"

ParamDec::~ParamDec(){
	size_t length = myDecs.size();
	for(size_t i = 0; i < length; i++){
	delete myDecs[i];
	}
	myDecs.clear();
}

string ParamDec::buildIR(CFG* cfg){
	return "";
}
