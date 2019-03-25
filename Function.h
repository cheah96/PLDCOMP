#pragma once
#include <string>
#include <fstream>
//#include "DefFunc.h"
//#include "DecFunc.h"
using namespace std;

class CFG;

class Parameter;

enum FUNCTYPE{
    DEFINITION,
    DECLARATION
};

class Function{
   public:
      /*Function(DefFunc* oneDef);
      Function(DecFunc* oneDec);*/
      Function(){}
      virtual ~Function(){}//delete def; delete dec;
      virtual void addParameter(Parameter* param) = 0;
      virtual void generateCode(ofstream& o) = 0;
      virtual string buildIR(CFG* cfg) = 0;
      virtual string getName() = 0;
      /*virtual Type* getType() = 0;
      virtual Parameter* getParams() = 0;
      virtual Block* getBlock(){}*/
      
    /*protected:
       FUNCTYPE type;
       DefFunc* def;
       DecFunc* dec;*/

};
