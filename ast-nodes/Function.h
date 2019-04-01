#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Type.h"
#include "ParamDec.h"
using namespace std;

class CFG;

class Parameter;

/*Node which represents a function (a declaration of function or a definition of function)*/

class Function{
    public:
        Function(string oneName, Type* oneType, ParamDec* oneDec) : name(oneName), returnType(oneType), decParams(oneDec){}
        virtual ~Function(){}
	/*Creates the correspondant IR instruction of this node in CFG*/
        virtual string buildIR(CFG* cfg) = 0;
        virtual string getName() = 0;
	Type* getReturnType(){return returnType;}

    protected:
	    string name;
    	Type* returnType;
    	ParamDec* decParams;
};
