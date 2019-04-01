#pragma once
#include <vector>
#include "Statement.h"
#include "Param.h"
#include "Expression.h"
using namespace std;

/*Node which represents a call of function*/

class ExecFuncNormal : Expr{
	public:
		ExecFuncNormal(string oneName, Param* oneParams) : funcName(oneName), myParams(oneParams) { type=Type("unknown"); }
		virtual ~ExecFuncNormal();
		int eval (){
			return 0;
		}
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
      
	protected:
	    string funcName;
		Param* myParams;
};
