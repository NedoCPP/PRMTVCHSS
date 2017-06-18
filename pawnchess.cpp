#include <iostream>
#include "pawnchess.h"


bool PawnChess::step(int x, int y, BoardChess* board)
{
    possibleMoves(board);

    for(auto it=moves.begin();it<=moves.end()-1;it++)
     {

        if(it->first==y-1&&it->second==x-1)
        {
            board->board[y-1][x-1]=nullptr;
            currentPos.first=y-1;
            currentPos.second=x-1;
            return 1;
        }

      else if(it==moves.end()-1)
        {
            {std::cout<<"move is impossible"<<std::endl;
                     return 0;}
        }
     }
}
PawnChess::PawnChess(int x,int y, std::string s,BoardChess* b,bool color)
{
    currentPos.first=y-1;
    currentPos.second=x-1;
    this->color=color;
    this->sign=s;
    b->board[y-1][x-1]=this;
}

void PawnChess::possibleMoves(BoardChess *board)
{
    int y=currentPos.first;
    int x=currentPos.second;

for(int i=0;i<4;i++)
 {
    switch(i)
    {
      case 0:
     {
        if(this->color==1){y-=1;x-=1;break;}
        else {y+=1;x-=1;break;}
     }
      case 1:
     {
       if(this->firstStep==0)
       {
        if(this->color==1){y-=2;this->firstStep=1;break;}
        else {y+=2;this->firstStep=1;break;}
       }
      else break;
     }
      case 2:
     {
        if(this->color==1){y-=1;break;}
        else {y+=1;break;}
     }
      case 3:
     {
        if(this->color==1){y-=1;x+=1;break;}
        else {y+=1;x-=1;break;}
     }
    }

       if(x>=0&&x<8&&y>=0&&y<8)
      {
         if(x==currentPos.second)
         {
          if(board->board[y][x]==nullptr||board->board[y][x]->color!=this->color);
              {moves.emplace_back(y,x);}
         }

       else
         {
           if(board->board[y][x]!=nullptr&&board->board[y][x]->color!=this->color)
             moves.emplace_back(y,x);
         }

      }

      x=currentPos.second;
      y=currentPos.first;
 }



}
