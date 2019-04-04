#pragma once
#include <string>
#include "Statement.h"
#include "Expression.h"
#include "Block.h"
using namespace std;


class For : public Statement {
    public:
        For(Statement* oneInit, Expr* oneExpr, Block* oneBlock, Statement* afterFor) : init(oneInit), myCondition(oneExpr), myBlock(oneBlock){myBlock->addStatement(afterFor);}
		For(Statement* oneInit, Expr* oneExpr, Statement* oneStatement, Statement* afterFor);
        virtual ~For();

	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR(CFG* cfg);
    protected:
		Statement* init;
        Expr* myCondition;
		Block * myBlock;
};
