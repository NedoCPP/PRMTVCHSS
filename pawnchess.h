#ifndef PAWNCHESS_H
#define PAWNCHESS_H

#include "basechess.h"
#include <string>


struct PawnChess:public BaseChess
{
    bool firstStep=false;
    bool step(int x, int y, BoardChess*) override;
    PawnChess(int,int,std::string,BoardChess*,bool);
    PawnChess(PawnChess&&,BoardChess*);
    ~PawnChess(){};
    void possibleMoves(BoardChess* board);
};





#endif // PAWNCHESS_H
