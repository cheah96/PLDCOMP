#pragma once
#include "Expression.h"
using namespace std;

class Param{
   public:
      Param(){ }
      virtual ~Param();
      void addExpr(Expr* e){
       myExprs.push_back(e);
      }
      vector<string> buildIR(CFG* cfg);
      
    protected:
       vector<Expr*> myExprs;
};