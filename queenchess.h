#ifndef QUEENCHESS_H
#define QUEENCHESS_H
#include "basechess.h"

struct QueenChess:public BaseChess
{
    std::vector<std::pair<int,int>> movesQuenn;//possible moves

       bool step(int x, int y, BoardChess*) override;
       QueenChess(int,int, std::string,BoardChess*,bool);

       void possibleMoves(BoardChess*);
       ~QueenChess(){};
};





#endif // QUEENCHESS_H
