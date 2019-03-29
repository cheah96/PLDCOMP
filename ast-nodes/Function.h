#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Type.h"
//#include "DecFunc.h"
using namespace std;

class CFG;

class Parameter;

class Function{
    public:
        Function(string oneName, Type* oneType) : name(oneName), returnType(oneType){}
        virtual ~Function(){}
        virtual void addParameter(Parameter* param) = 0;
        virtual string buildIR(CFG* cfg) = 0;
        virtual string getName() = 0;

    protected:
	    string name;
    	Type* returnType;
    	vector<Parameter*> params;
};
