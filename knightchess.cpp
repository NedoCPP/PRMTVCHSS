#include "knightchess.h"
#include <iostream>
#include <string>
struct BoardChess;



bool KnightChess::step(int x, int y, BoardChess *board)
{
    possibleMoves(board);

  for(auto it=movesKnight.begin();it<=movesKnight.end()-1;it++)
   {

      if(it->first==y-1&&it->second==x-1)
      {
          board->board[y-1][x-1]=nullptr;
          currentPos.first=y-1;
          currentPos.second=x-1;
          return 1;
      }

    else if(it==movesKnight.end()-1)
      {
          {std::cout<<"move is impossible"<<std::endl;
                   return 0;}
      }


   }

}
KnightChess::KnightChess(int x, int y, std::string s, BoardChess *board, bool color)
{
   this->sign=s;
   currentPos.first=y-1;
   currentPos.second=x-1;
   this->color=color;
   board->board[y-1][x-1]=this;
}
void KnightChess::possibleMoves(BoardChess* board)
{

this->movesKnight.clear();


        if(currentPos.first-2>=0&&currentPos.second-1>=0)
        {
               movesKnight.emplace_back(currentPos.first-2,currentPos.second-1);
        }


        if(currentPos.first-2>=0&&currentPos.second+1<=7)
        {
               movesKnight.emplace_back(currentPos.first-2,currentPos.second+1);
        }

        if(currentPos.first-1>=0&&currentPos.second-2>=0)
         {
                movesKnight.emplace_back(currentPos.first-1,currentPos.second-2);
         }

        if(currentPos.first-1>=0&&currentPos.second+2<=7)
        {
               movesKnight.emplace_back(currentPos.first-1,currentPos.second+2);
        }

         if(currentPos.first+1<=7&&currentPos.second-2>=0)
         {
                movesKnight.emplace_back(currentPos.first+1,currentPos.second-2);
         }

         if(currentPos.first+1<=7&&currentPos.second+2<=7)
         {
                movesKnight.emplace_back(currentPos.first+1,currentPos.second+2);
         }


         if(currentPos.first+2<=7&&currentPos.second-1>=0)
         {
                movesKnight.emplace_back(currentPos.first+2,currentPos.second-1);
         }
         if(currentPos.first+2<=7&&currentPos.second+1<=7)
         {
                movesKnight.emplace_back(currentPos.first+2,currentPos.second+1);

         }



}
