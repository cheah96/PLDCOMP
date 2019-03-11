#pragma once
#include <string>

using namespace std;

enum ENUMTYPE{
    VOID,
    INT,
    CHAR,
    ERROR
};

class Type{
   public:
      Type(string oneType);
      virtual ~Type(){}//delete def; delete dec;

    protected:
        ENUMTYPE myType;

};