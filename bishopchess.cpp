#include "bishopchess.h"
#include <iostream>
#include <string>
struct BoardChess;

BishopChess::BishopChess(int x, int y, std::string s, BoardChess *board, bool color)
{
    this->color=color;
    this->sign=s;
    currentPos.first=y-1;
    currentPos.second=x-1;
    board->board[y-1][x-1]=this;

}
bool BishopChess::step(int x, int y, BoardChess *board)
{
   possibleMoves(board);

   for(auto it=movesBishop.begin();it<=movesBishop.end()-1;it++)
    {

       if(it->first==y-1&&it->second==x-1)
       {
           board->board[y-1][x-1]=nullptr;
           currentPos.first=y-1;
           currentPos.second=x-1;
           return 1;
       }

     else if(it==movesBishop.end()-1)
       {
           {std::cout<<"move is impossible"<<std::endl;
                    return 0;}
       }


    }
}
void BishopChess::possibleMoves(BoardChess *board)
{
this->movesBishop.clear();
int x=currentPos.second;
int y=currentPos.first;

    while(x>=1&&y>=1)
    {
     if(board->board[y-1][x-1]==nullptr)
       movesBishop.emplace_back(y-1,x-1);
     else if(board->board[y-1][x-1]->color==this->color)
       break;
     else if(board->board[y-1][x-1]->color!=this->color)
       {
           movesBishop.emplace_back(y-1,x-1);
           break;
       }
     y-=1;
     x-=1;

    }
    ////////////////////////////////////////////////////
     x=currentPos.second;
     y=currentPos.first;

    while(x>=1&&y<=6)
    {
     if(board->board[y+1][x-1]==nullptr)
       movesBishop.emplace_back(y+1,x-1);
     else if(board->board[y+1][x-1]->color==this->color)
       break;
     else if(board->board[y+1][x-1]->color!=this->color)
       {
           movesBishop.emplace_back(y+1,x-1);
           break;
       }
     y+=1;
     x-=1;
    }
    /////////////////////////////////////////////////////

    x=currentPos.second+1;
    y=currentPos.first+1;

   while(x<=8&&y<=7)
   {
    if(board->board[y][x]==nullptr)
      movesBishop.emplace_back(y,x);
    else if(board->board[y][x]->color==this->color)
      break;
    else if(board->board[y][x]->color!=this->color)
      {
          movesBishop.emplace_back(y,x);
          break;
      }
    y+=1;
    x+=1;
   }
////////////////////////////////////////////////////////////
   x=currentPos.second;
   y=currentPos.first;

  while(x<=7&&y>=1)
  {
   if(board->board[y-1][x+1]==nullptr)
     movesBishop.emplace_back(y-1,x+1);
   else if(board->board[y-1][x+1]->color==this->color)
     break;
   else if(board->board[y-1][x+1]->color!=this->color)
     {
         movesBishop.emplace_back(y-1,x+1);
         break;
     }
   y-=1;
   x+=1;
  }



}
