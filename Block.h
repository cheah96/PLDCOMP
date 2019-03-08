#pragma once
#include <vector>
#include "Statement.h"
using namespace std;

class Block{
   public:
      Block() { }
      virtual ~Block();
      void addStatement(Statement* stat){
       stats.push_back(stat);
      }
      
    protected:
       vector<Statement*> stats; 
};