#ifndef ROOKCHESS_H
#define ROOKCHESS_H

#include "basechess.h"

struct RookChess:public BaseChess
{
    std::vector<std::pair<int,int>> moves;//possible moves

       bool step(int x, int y, BoardChess*) override;
       RookChess(int,int, std::string,BoardChess*,bool);

       void possibleMoves(BoardChess*);
       ~RookChess(){};
};

#endif // ROOKCHESS_H
