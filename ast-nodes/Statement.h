#pragma once
#include <fstream>
#include "../gen-assembly/CFG.h"
using namespace std;

class CFG;

class Statement {
   public:
      Statement() { }
      virtual ~Statement() { }
      virtual void generateCode(ofstream& o) = 0;
      virtual string buildIR(CFG * cfg) = 0;
};
