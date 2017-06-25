#include <iostream>
#include <string>
#include "kingchess.h"

KingChess::KingChess(int x, int y, std::string s, BoardChess *board, bool color)
{
    this->color=color;
    this->sign=s;
    currentPos.first=y-1;
    currentPos.second=x-1;
    board->board[y-1][x-1]=this;
}


bool KingChess::step(int x, int y, BoardChess *board)
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


void KingChess::possibleMoves(BoardChess *board)
{
    this->moves.clear();
    int x=currentPos.second;
    int y=currentPos.first;


    for(int i=0;i<7;i++)
    {
         x=currentPos.second;
         y=currentPos.first;


         switch (i)
         {
             case 0:{y--;break;};
         case 1:{y--;x--;break;};
             case 2:{x--;break;};
         case 3:{y++;x--;break;};
             case 4:{y++;break;};
         case 5:{y++;x++;break;};
             case 6:{x++;break;};
         case 7:{y--;x++;break;};
         }


 if(x>=0&&x<=7&&y>=0&&y<=7)
    {
     std::swap(board->board[y][x],
               board->board[currentPos.first][currentPos.second]);

     for(auto& a:board->board)//a=vector<BaseChess*>
     {
         for(auto& b:a)//b=BaseChess*
         {
             if(b==nullptr)continue;
            else if(b!=this)
             {
                if(b->step(x,y,board));
                  else this->moves.emplace_back(y,x);
             }
         }
     }






    std::swap(board->board[currentPos.first][currentPos.second],
              board->board[y][x]);

    }
}



}
