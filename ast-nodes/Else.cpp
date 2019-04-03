#include "Else.h"

Else::Else(Statement* oneStatement)
{
	myBlock = new Block;
	myBlock->addStatement(oneStatement);
}

Else::~Else()
{
	if(myBlock != nullptr){
		delete myBlock;
	}
}

string Else::buildIR(CFG* cfg){
    myBlock->buildIR(cfg);
    return "";
}
