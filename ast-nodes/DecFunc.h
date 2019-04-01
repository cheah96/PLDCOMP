#pragma once
#include <string>
#include "Function.h"
#include "Parameter.h" 
using namespace std;

/*Node which represents a declaration of function*/

class DecFunc : public Function{
	public:
		DecFunc(string oneName, string oneType, ParamDec* oneDec) : Function(oneName, new Type(oneType), oneDec) {}
		~DecFunc();
		//void addParameter(Parameter* param);
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
		string getName() { return name;}
};
