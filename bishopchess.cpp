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


for(int i=0;i<4;i++)
{

  while(x>=0&&x<8&&y>=0&&y<8)
    {
     if(board->board[y][x]==this){}
  else{
      if(board->board[y][x]==nullptr)
        movesBishop.emplace_back(y,x);
      else if(board->board[y][x]->color==this->color)
        break;
      else if(board->board[y][x]->color!=this->color)
        {
            movesBishop.emplace_back(y,x);
            break;
        }
     }

      switch(i)
      {
        case 0:{y-=1;x-=1;break;}
        case 1:{x-=1;y+=1;break;}
        case 2:{y+=1;x+=1;break;}
        case 3:{x+=1;y-=1;break;}
      }
}
    x=currentPos.second;
    y=currentPos.first;
}






}
