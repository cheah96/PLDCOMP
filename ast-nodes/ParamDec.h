#pragma once
#include "Parameter.h"
#include "../gen-assembly/CFG.h"
using namespace std;

/*Node which represents a sequence of parameters*/

class ParamDec{
   public:
        ParamDec(){ }
        virtual ~ParamDec();
        void addParameter(Parameter* p){
            myDecs.push_back(p);
        }
        vector<Parameter*> getParameters() { return myDecs; }
	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR(CFG* cfg);
      
    protected:
        vector<Parameter*> myDecs;
};
