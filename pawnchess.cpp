#include <iostream>
#include "pawnchess.h"


bool PawnChess::step(int x, int y, BoardChess* board)
{
if(board->board[y-1][x-1]==nullptr)//На клетке никого, запраш. клетка - (текущая+1)
 {
    if(((currentPos.first==y&&currentPos.second==x-1&&this->color==1)//Простые ходы для белых
    ||(currentPos.first==y-2&&currentPos.second==x-1&&this->color==0))//Для черных

    ||((currentPos.first==y+1&&currentPos.second==x-1&&this->color==1&&firstStep==false)//Возможности(2клетки) первого шага.white
    ||(currentPos.first==y-3&&currentPos.second==x-1&&this->color==0&&firstStep==false)))//black
    {

        if((y==1&&color==1)
        ||(y==8&&color==0))
        {
            std::cout<<"TTRRRAAANSSFFFORMATION!!!!"<<std::endl;
        }

         firstStep=true;
         currentPos.first=y-1;
         currentPos.second=x-1;
         return 1;
    }

    else {std::cout<<"move is impossible"<<std::endl;
         return 0;}

 }
else
 {
     if(board->board[y-1][x-1]->color!=this->color)//Если в клетке неприятель
       {
         if
           ( (((currentPos.first==y&&currentPos.second==x)//для белых
           ||(currentPos.first==y&&currentPos.second==x-2))
           &&(this->color==1))
           ||(((currentPos.first==y-2&&currentPos.second==x)//для черных
           ||(currentPos.first==y-2&&currentPos.second==x-2))
           &&(this->color==0)))

         {
             board->board[y-1][x-1]=nullptr;
             currentPos.first=y-1;
             currentPos.second=x-1;
             return 1;
         }
          else return 0;
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

