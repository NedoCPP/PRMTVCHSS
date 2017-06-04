#ifndef KNIGHTCHESS_H
#define KNIGHTCHESS_H

#include "basechess.h"
#include <string>

struct KnightChess:public BaseChess
{
   std::vector<std::pair<int,int>> movesKnight;//possible moves

      bool step(int x, int y, BoardChess*) override;
      KnightChess(int,int, std::string,BoardChess*,bool);

      void possibleMoves(BoardChess*);
      ~KnightChess(){};
};


#endif // KNIGHTCHESS_H
