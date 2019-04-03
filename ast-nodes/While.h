#pragma once
#include <string>
#include "Statement.h"
#include "Expression.h"
#include "Block.h"
using namespace std;


class While : public Statement {
    public:
        While(Expr* oneExpr, Block* oneBlock) : myCondition(oneExpr), myBlock(oneBlock){}
		While(Expr* oneExpr, Statement* oneStatement);
        virtual ~While();

	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR(CFG* cfg);
    protected:
        Expr* myCondition;
		Block * myBlock;
};
