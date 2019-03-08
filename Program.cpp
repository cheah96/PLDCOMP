#include "Program.h"

Program::Program(){
}

Program::~Program() { 
    size_t length = funcs.size();
    for(size_t i = 0; i < length; i++){
        delete funcs[i];
    }
    funcs.clear();
}

/*void Program::addFunction(Function* func){
    funcs.push_back(func);
}*/