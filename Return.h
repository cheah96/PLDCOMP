#pragma once
#include "Expression.h"
#include "Statement.h"
using namespace std;


class Return : public Statement {
   public:
      Return(Expr* oneExpr) : expr(oneExpr) { }
      ~Return() { delete expr;}
      
    protected:
       Expr* expr; 
};