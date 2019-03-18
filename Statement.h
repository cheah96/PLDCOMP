#pragma once
#include <fstream>
using namespace std;

class Statement {
   public:
      Statement() { }
      virtual ~Statement() { }
      virtual void generateCode(ofstream& o) = 0;
      virtual string buildIR(CFG * cfg) = 0;
};