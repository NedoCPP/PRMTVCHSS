#ifndef QUEENCHESS_H
#define QUEENCHESS_H
#include "basechess.h"

struct QueenChess:public BaseChess
{
    std::vector<std::pair<int,int>> moves;//possible moves

       bool step(int x, int y, BoardChess*) override;
       QueenChess(int,int, std::string,BoardChess*,bool);

       void possibleMoves(BoardChess*)override;
       ~QueenChess(){};
};





#endif // QUEENCHESS_H
