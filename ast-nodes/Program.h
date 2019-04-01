#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Function.h"
using namespace std;

/*Node which represents a program*/

class Program{
    public:
        Program();
        virtual ~Program();
        void addFunction(Function* func){
            funcs.push_back(func);
        }
        //vector<Function*> getFuncs(){return funcs;}
	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR();
        void generateCode(ofstream& o);
	Type* getFuncReturn(string name);
            
    protected:
        vector<Function*> funcs;
        vector<CFG*> cfgs;
};
