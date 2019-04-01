#pragma once
#include <fstream>
#include "../gen-assembly/CFG.h"
using namespace std;

class CFG;

/*Node which represents a statement*/

class Statement {
    public:
        Statement() { }
        virtual ~Statement() { }
	/*Creates the correspondant IR instruction of this node in CFG*/
        virtual string buildIR(CFG * cfg) = 0;
};
