#pragma once
#include "Expression.h"
#include "Statement.h"
using namespace std;


class Return : public Statement {
   public:
      Return(Expr* oneExpr) : expr(oneExpr) { }
      ~Return() { delete expr;}
      virtual void generateCode(ofstream& o){
        
         o << "   movl  ";
         expr->generateCode(o);
         o << "," << " %eax\n";
      }
    protected:
       Expr* expr; 
};