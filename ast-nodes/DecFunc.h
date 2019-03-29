#pragma once
#include <string>
#include "Function.h"
#include "Parameter.h" 
using namespace std;

class DecFunc : public Function{
	public:
		DecFunc(string oneName, string oneType) : Function(oneName, new Type(oneType)) {}
		~DecFunc();
		void addParameter(Parameter* param);
		string buildIR(CFG* cfg);
		string getName() { return name;}
};
