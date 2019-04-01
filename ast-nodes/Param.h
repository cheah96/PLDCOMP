#pragma once
#include "Expression.h"
using namespace std;

/*Node which represents a sequence of parameters*/

class Param{
   public:
        Param(){ }
        virtual ~Param();
        void addExpr(Expr* e){
            myExprs.push_back(e);
        }
	/*Creates the correspondant IR instruction of this node in CFG*/
        vector<string> buildIR(CFG* cfg);
      
    protected:
        vector<Expr*> myExprs;
};
