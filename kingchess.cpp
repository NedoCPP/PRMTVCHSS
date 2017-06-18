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



        for(int i=0;i<8;i++)
         {
             x=currentPos.second;
             y=currentPos.first;

            switch(i)
            {
              case 0:{y-=1;break;}
              case 1:{x-=1;break;}
              case 2:{y+=1;break;}
              case 3:{x+=1;break;}
              case 4:{y-=1;x-=1;break;}
              case 5:{x-=1;y+=1;break;}
              case 6:{y+=1;x+=1;break;}
              case 7:{x+=1;y-=1;break;}
            }


  if(board->board[y][x]==nullptr)
  {
      for(auto& it:board->pawns)//it-unique_ptr`s to BaseChess
        {
          for(auto& jt:it->moves)//through the moves of BaseChess
          {
            if(jt.first==y&&jt.second==x)
             break;// if [y][x]-one of potential moves of it

          }


        }
      moves.emplace_back(y,x);

      }
else break;
         }


}
