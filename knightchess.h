#ifndef KNIGHTCHESS_H
#define KNIGHTCHESS_H

#include "basechess.h"
#include <string>
#include<vector>

struct KnightChess:public BaseChess
{
   std::vector<std::pair<int,int>> moves;//possible moves

      bool step(int x, int y, BoardChess*) override;
      KnightChess(int,int, std::string,BoardChess*,bool);

      void possibleMoves(BoardChess*)override;
      ~KnightChess(){};
};


#endif // KNIGHTCHESS_H
