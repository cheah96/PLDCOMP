#pragma once
#include <string>
#include <vector>
#include "Function.h"
#include "Parameter.h" 
using namespace std;



class DecFunc : public Function{
   public:
      DecFunc(string oneName, string oneType) : name(oneName), typeReturn(oneType){ }
      ~DecFunc();
      void addParameter(Parameter* param);
      
    protected:
       string name;
       string typeReturn;
       vector<Parameter*> params;
};