#include "Block.h"

Block::~Block() { 
    size_t length = stats.size();
    for(size_t i = 0; i < length; i++){
        delete stats[i];
    }
    stats.clear();
}

/*void Block::addStatement(Statement* stat){
    stats.push_back(stat);
}*/