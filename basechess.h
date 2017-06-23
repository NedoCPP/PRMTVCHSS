#ifndef BASECHESS_H
#define BASECHESS_H

#include <utility>
#include "boardchess.h"
#include <string>
#include <vector>


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
    std::vector<std::pair<int,int>> moves;
    virtual void possibleMoves(BoardChess*)=0;
};


#endif // BASECHESS_H
