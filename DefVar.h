#pragma once
#include <string>
#include <vector>
#include "Type.h"
#include "Statement.h"
using namespace std;

class DefVar : public Statement{
   public:
      DefVar() : {}
      virtual ~DefVar(){}
      virtual void generateCode(ofstream& o) = 0;
      virtual string buildIR(CFG * cfg) = 0;
};


class DefVarWithDeclar : public DefVar{
   public:
      DefVarWithDeclar( string oneType, string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myType = new Type(oneType); myVar = new ExprVar(oneName); }
      virtual ~DefVarWithDeclar(){delete myType; delete myExpr; delete myVar;}
      virtual void generateCode(ofstream& o){}
      string buildIR(CFG * cfg);
    protected:
       ExprVar* myVar;
       Type* myType;
       Expr* myExpr; 
};

class DefVarWithoutDeclar : public DefVar{
   public:
      DefVarWithoutDeclar(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); }
      virtual ~DefVarWithoutDeclar(){delete myExpr; delete myVar;}
      virtual void generateCode(ofstream& o){}
      string buildIR(CFG * cfg);
    protected:
       ExprVar* myVar;
       Expr* myExpr; 
};