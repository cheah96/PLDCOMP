#pragma once
#include <string>
//#include "DefFunc.h"
//#include "DecFunc.h"
using namespace std;

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
      
    /*protected:
       FUNCTYPE type;
       DefFunc* def;
       DecFunc* dec;*/

};