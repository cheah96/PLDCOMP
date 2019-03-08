#pragma once
#include <string>
#include <vector>
#include "Function.h"
using namespace std;

class Program{
   public:
      Program();
      virtual ~Program();
      void addFunction(Function* func){
         funcs.push_back(func);
      }
            
    protected:
        vector<Function*> funcs;

};