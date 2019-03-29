#pragma once
#include <string>
#include <vector>
#include "Type.h"
#include "Statement.h"
using namespace std;

class DeclarVar : public Statement{
   public:
		DeclarVar(vector<string>* oneVars, string oneType) : myVars(oneVars){myType = new Type(oneType); }
		~DeclarVar();
		string buildIR(CFG* cfg);
      
    protected:
		vector<string>* myVars;
		Type* myType;
};
