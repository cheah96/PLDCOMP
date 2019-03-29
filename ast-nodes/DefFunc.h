#pragma once
#include "Function.h"
#include <string>
#include "Parameter.h" 
#include "Block.h"

using namespace std;

class DefFunc : public Function{
	public:
		DefFunc( string oneType, string oneName, Block* oneBlock ) : Function(oneName, new Type(oneType)), block(oneBlock) {}
		~DefFunc();
		void addParameter(Parameter* param);
		string getName() { return name;}
		string buildIR(CFG* cfg);
	  
	protected:
	   Block* block;
};
