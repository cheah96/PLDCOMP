#pragma once
#include <string>
#include "Expression.h"
#include "Statement.h"
using namespace std;

class ExprStat : public Statement{
    public:
        ExprStat(Expr* oneExpr) : myExpr(oneExpr){}
        virtual ~ExprStat();
        string buildIR(CFG* cfg);
        void generateCode(ofstream& o){

        }      
    protected:
        Expr* myExpr;
};