#pragma once
#include <string>
#include "Type.h"
using namespace std;

/*Node which represents just one parameter*/

class Parameter{
    public:
        Parameter(string oneName, string oneType) : name(oneName){myType = new Type(oneType); }
        virtual ~Parameter(){delete myType;}
      
    protected:
        string name;
        Type* myType;
};
