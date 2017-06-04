#ifndef BASECHESS_H
#define BASECHESS_H

#include <utility>
#include "boardchess.h"
#include <string>


struct BoardChess;

struct BaseChess
{
    int ID;
    bool color;//0-black, 1- white
    std::string sign;
    std::pair<int,int> currentPos;
    bool existing;
    virtual bool step(int,int,BoardChess*)=0;
    BaseChess(std::string s):sign(std::move(s)){}
    BaseChess(){}
    virtual ~BaseChess(){};
};


#endif // BASECHESS_H
