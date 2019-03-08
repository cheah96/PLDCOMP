#pragma once
#include <string>
using namespace std;


class Parameter{
   public:
      Parameter(string oneName, string oneType) : name(oneName), type(oneType){ }
      virtual ~Parameter(){}
      
    protected:
       string name;
       string type;
};