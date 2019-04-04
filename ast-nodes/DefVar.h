#pragma once
#include <string>
#include <vector>
#include "Type.h"
#include "Statement.h"
#include "Expression.h"

using namespace std;

/*Node which represents a definition of a variable*/

class CFG;

class DefVar : public Statement{
	public:
		DefVar() {}
		virtual ~DefVar(){}
		/*Creates the correspondant IR instruction of this node in CFG*/
		virtual string buildIR(CFG * cfg) = 0;
};


class DefVarWithDeclar : public DefVar{
	public:
		DefVarWithDeclar( string oneType, string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myType = new Type(oneType); myVar = new ExprVar(oneName); }
		virtual ~DefVarWithDeclar(){delete myType; delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Type* myType;
		Expr* myExpr; 
};
