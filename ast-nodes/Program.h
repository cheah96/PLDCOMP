#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Function.h"
using namespace std;

class Program{
    public:
        Program();
        virtual ~Program();
        void addFunction(Function* func){
            funcs.push_back(func);
        }
        //vector<Function*> getFuncs(){return funcs;}
        string buildIR();
        void generateCode(ofstream& o);
            
    protected:
        vector<Function*> funcs;
        vector<CFG*> cfgs;
};
