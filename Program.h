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
      void generateCode(ofstream& o);
      string buildIR();
            
    protected:
        vector<Function*> funcs;
        vector<CFG*> cfgs;

};
