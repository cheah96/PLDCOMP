#pragma once
#include "Function.h"
#include <string>
#include "Parameter.h" 
#include "Block.h"

using namespace std;

/*Node which represents a definition of function*/

class DefFunc : public Function{
	public:
		DefFunc( string oneType, string oneName, Block* oneBlock, ParamDec* oneDec ) : Function(oneName, new Type(oneType), oneDec), block(oneBlock) {}
		~DefFunc();
		//void addParameter(Parameter* param);
		string getName() { return name;}
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
	  
	protected:
	   Block* block;
};
