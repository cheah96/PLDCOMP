#pragma once
#include <string> 
#include "Block.h"
#include "../gen-assembly/CFG.h"
using namespace std;


class Else {
    public:
        Else(Block* oneBlock) : myBlock(oneBlock){}
		Else(Statement* oneStatement);
        virtual ~Else();

	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR(CFG* cfg);
    protected:
		Block * myBlock;
};
