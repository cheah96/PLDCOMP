#pragma once
#include <fstream>
#include "../gen-assembly/CFG.h"
using namespace std;

class CFG;

class Statement {
    public:
        Statement() { }
        virtual ~Statement() { }
        virtual string buildIR(CFG * cfg) = 0;
};
