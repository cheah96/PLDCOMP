#pragma once
#include "Function.h"
#include <string>
#include <vector>
#include "Parameter.h" 
#include "Type.h"
#include "Block.h"

using namespace std;

class DefFunc : public Function{
   public:
      DefFunc( string oneType, string oneName, Block* oneBlock ) : block(oneBlock), name(oneName){ returnType = new Type(oneType); }
      ~DefFunc();
      void addParameter(Parameter* param);
      string getName() { return name;}
      virtual void generateCode(ofstream& o){
         o << "   .globl	" << name << endl;
         o << name << ":" << endl;
         o << "   pushq	%rbp" << endl; 
         o << "   movq	%rsp, %rbp" << endl;
         block->generateCode(o);
         o << "   popq	%rbp" << endl;
         o << "   ret" << endl;
      }
      string buildIR(CFG* cfg);
      
    protected:
       string name;
       Type* returnType;
       vector<Parameter*> params;
       Block* block;
};
