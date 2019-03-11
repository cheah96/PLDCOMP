#pragma once
#include <string>
#include <vector>
#include "Type.h"
#include "Statement.h"
using namespace std;



class DefVar : public Statement{
   public:
      DefVar( string oneType, string oneName, Expr* oneExpr ) : myExpr(oneExpr), name(oneName){ myType = new Type(oneType); }
      virtual ~DefVar(){delete myType; delete myExpr;}
      virtual void generateCode(ofstream& o){}
      
    protected:
       string name;
       Type* myType;
       Expr* myExpr; 
};