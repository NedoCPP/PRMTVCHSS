#ifndef KINGCHESS_H
#define KINGCHESS_H

#include "basechess.h"
#include<vector>

struct KingChess:public BaseChess
{
    std::vector<std::pair<int,int>> moves;//possible moves

       bool step(int x, int y, BoardChess*) override;
       KingChess(int,int, std::string,BoardChess*,bool);
       void possibleMoves(BoardChess*) override;

       ~KingChess(){};
};






#endif // KINGCHESS_H
