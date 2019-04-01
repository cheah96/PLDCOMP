#pragma once
#include "Expression.h"
#include "Statement.h"
using namespace std;

/*Node which represents a return instruction*/

class Return : public Statement {
    public:
        Return(Expr* oneExpr) : expr(oneExpr) { }
        ~Return() { delete expr;}
	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR(CFG * cfg);
    protected:
        Expr* expr; 
};
