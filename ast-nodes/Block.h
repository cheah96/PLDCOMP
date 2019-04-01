#pragma once
#include <vector>
#include "Statement.h"
#include <fstream>
using namespace std;

/*Node which represents a block containing a sequence of statements*/

class Block{
	public:
		Block() { }
		virtual ~Block();
		void addStatement(Statement* stat){
			stats.push_back(stat);
		}
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
      
    protected:
       vector<Statement*> stats; 
};
