#ifndef BISHOPCHESS_H
#define BISHOPCHESS_H

#include "basechess.h"
#include <string>

struct BishopChess:public BaseChess
{
    std::vector<std::pair<int,int>> moves;//possible moves

       bool step(int x, int y, BoardChess*) override;
       BishopChess(int,int, std::string,BoardChess*,bool);

       void possibleMoves(BoardChess*) override;
       ~BishopChess(){};
};




#endif // BISHOPCHESS_H
