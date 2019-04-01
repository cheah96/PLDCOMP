#pragma once
#include <string>
#include "Expression.h"
#include "Statement.h"
using namespace std;

/*Node which represents a statement which is just an expression*/

class ExprStat : public Statement{
    public:
        ExprStat(Expr* oneExpr) : myExpr(oneExpr){}
        virtual ~ExprStat();
	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR(CFG* cfg);
    protected:
        Expr* myExpr;
};
