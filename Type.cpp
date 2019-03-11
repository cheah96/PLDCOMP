#include "Type.h"

Type::Type(string oneType){
    if(oneType == "int"){
        myType = INT;
    }
    else if(oneType == "void"){
        myType = VOID;
    }
    else if(oneType == "char"){
        myType = CHAR;
    }else{
        myType = ERROR;
    }
}