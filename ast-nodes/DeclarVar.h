#pragma once
#include <string>
#include <vector>
#include "Type.h"
#include "Statement.h"
using namespace std;

/*Node which represents a declaration of variables*/

class DeclarVar : public Statement{
   public:
		DeclarVar(vector<string>* oneVars, string oneType) : myVars(oneVars){myType = new Type(oneType); }
		~DeclarVar();
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
      
    protected:
		vector<string>* myVars;
		Type* myType;
};
