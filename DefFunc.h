#pragma once
#include "Function.h"
#include <string>
#include <vector>
#include "Parameter.h" 
#include "Block.h" 
using namespace std;



class DefFunc : public Function{
   public:
      DefFunc( string oneType, string oneName, Block* oneBlock ) : block(oneBlock), name(oneName), typeReturn(oneType){ }
      ~DefFunc();
      void addParameter(Parameter* param);
      
    protected:
       string name;
       string typeReturn;
       vector<Parameter*> params;
       Block* block;
};