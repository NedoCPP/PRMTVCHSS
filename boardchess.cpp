#include "pawnchess.h"
#include "knightchess.h"
#include "boardchess.h"
#include "bishopchess.h"
#include "rookchess.h"
#include <iostream>
#include <memory>
#include <string>

BoardChess::BoardChess():board(8,std::vector<BaseChess*>(8,nullptr)){};
bool BoardChess::onBoard(int x1, int y1,int x2, int y2)// x1,y1- координаты выбора фигуры, x2,y2- куда ходить
{
   if(board[y1-1][x1-1]!=nullptr)
{
      if(board[y1-1][x1-1]->color!=color)
        {
          std::cout<<"Isn`t your move!"<<std::endl;
          return 0;
        }

      if(board[y1-1][x1-1]->step(x2,y2,this))
        {
            std::swap(board.at(y1-1).at(x1-1),board.at(y2-1).at(x2-1));
            color=!color;
        }
      else return 0;

}
   else {std::cout<<"no figure at "<<x1<<" : "<<y1<<std::endl;
         return 0;}

}
void BoardChess::draw()//Отрисовка поля. Ваш К.
{
    if(color==1) std::cout<<"White"<<std::endl;
     else std::cout<<"Black"<<std::endl;

int N=1;
std::cout<<"___1__2__3__4__5__6__7__8__"<<std::endl;
    for(auto i:board)
     {
      std::cout<<N<<" |";
        for(auto j: i)
         {
          if(j==nullptr)
           {std::cout<<" ";}
          else
           {std::cout<<j->sign;}
          std::cout<<" |";

         }
    std::cout<<"\n---------------------------"<<std::endl;
    N+=1;
 }
}
void BoardChess::start() //Основной цикл
{
 int x1,y1,x2,y2;
 int N=1;//count для велосипеда
 std::vector<std::unique_ptr<BaseChess>> pawns;

 /*
 for(int i=1;i<=8;i++)
 {
   std::unique_ptr<PawnChess> p0(new PawnChess(i,7,"W",this,1));
   std::unique_ptr<PawnChess> p1(new PawnChess(i,2,"B",this,0));
   pawns.emplace_back(std::move(p0));
   pawns.emplace_back(std::move(p1));
 }
*/

  std::unique_ptr<RookChess> b(new RookChess(8,5,"1",this,1));
  pawns.emplace_back(std::move(b));

  std::unique_ptr<RookChess> b2(new RookChess(1,5,"0",this,0));
  pawns.emplace_back(std::move(b2));


    for(;;)
    {

  draw();
  std::cin>>x1>>y1>>x2>>y2;
  std::system("clear");
  onBoard(x1,y1,x2,y2);

 }

}

