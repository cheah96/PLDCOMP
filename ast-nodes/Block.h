#pragma once
#include <vector>
#include "Statement.h"
#include <fstream>
using namespace std;

class Block{
   public:
      Block() { }
      virtual ~Block();
      void addStatement(Statement* stat){
       stats.push_back(stat);
      }
      void generateCode(ofstream& o){
         for(Statement* stat : stats){
            stat->generateCode(o);
         }
      }
      string buildIR(CFG* cfg);
      
    protected:
       vector<Statement*> stats; 
};
