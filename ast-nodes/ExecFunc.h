#pragma once
#include <vector>
#include "Statement.h"
#include "Param.h"
#include "Expression.h"
using namespace std;

class ExecFunc : Expr{
   public:
      ExecFunc(string oneName, Param* oneParams) : funcName(oneName), myParams(oneParams) { type=Type("unknown"); }
      virtual ~ExecFunc();
      int eval (){
          return 0;
      }
      void generateCode(ofstream& o){
      }
      string buildIR(CFG* cfg);
      
    protected:
        string funcName;
        Param* myParams;
};