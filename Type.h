#pragma once
#include <string>

using namespace std;

enum ENUMTYPE{
    VOID,
    INT,
    CHAR,
    ERROR
};

const string typeLabel[4] = {"void","int","char","error"};

class Type{
   public:
      Type(string oneType);
      virtual ~Type(){}//delete def; delete dec;
      string getText();
    protected:
        ENUMTYPE myType;

};