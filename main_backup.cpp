#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

struct BoardChess;

struct BaseChess
{
    int ID;
    bool color;//0-black, 1- white
    char sign;
    std::pair<int,int> currentPos;
    bool existing;
    virtual bool step(int,int,BoardChess*)=0;
};
struct PawnChess:public BaseChess
{
    bool firstStep;
    bool step(int x, int y, BoardChess*);
    PawnChess(int,int,char,BoardChess&,bool);
};
struct BoardChess
{
    std::vector<std::vector<BaseChess*>> board;
    BoardChess():board(8,std::vector<BaseChess*>(8,nullptr)){};
    bool onBoard(int,int,int,int);
    void draw();
    bool color=1;

};

//////////////////////////////////////////////////////////////////////////
bool BoardChess::onBoard(int x1, int y1,int x2, int y2)
{
   if(board[y1-1][x1-1]!=nullptr)
{
      if(board[y1-1][x1-1]->color!=color) return 0;


      if(board[y1-1][x1-1]->step(x2,y2,this))
        {
            std::swap(board.at(y1-1).at(x1-1),board.at(y2-1).at(x2-1));
            color=!color;
        }
      else
        {
            std::system("clear");
            //std::cout<<"Try again"<<std::endl;
        }
}
   else return 0;

}
void BoardChess::draw()
{
int N=1;
std::cout<<" _1_2_3_4_5_6_7_8_"<<std::endl;
 for(auto i:board)
 {
   std::cout<<N<<"|";
     for(auto j: i)
     {
         if(j==nullptr) {std::cout<<" ";}
         else {std::cout<<j->sign;}
         std::cout<<"|";

     }
    std::cout<<"\n------------------"<<std::endl;
//    std::cout<<std::endl;
    N+=1;
 }
}

//////////////////////////////////////////////////////////////////////////
bool PawnChess::step(int x, int y, BoardChess* board)
{
    if(board->board[y-1][x-1]==nullptr)//На клетке никого, запраш. клетка - (текущая+1)
     {
        if((currentPos.first==y&&currentPos.second==x-1&&this->color==1)//Простые ходы для белых
        ||(currentPos.first==y-2&&currentPos.second==x-1&&this->color==0))//Для черных
        {
            currentPos.first=y-1;
            currentPos.second=x-1;
            return 1;
        }     
        else return 0;
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
PawnChess::PawnChess(int x,int y,char s,BoardChess& bc,bool color)
{
   if(bc.board[y-1][x-1]==nullptr)
    {
        currentPos.first=y-1;
        currentPos.second=x-1;
        this->sign=s;
        this->color=color;
        bc.board[y-1][x-1]=this;
    }
   else {std::cout<<"Клетка занята"<<std::endl;}

}

///////////////////////////////////////////////////////////////////////////

int main()
{
  BoardChess board;
  PawnChess(5,6,'1',board,1);
  PawnChess(4,4,'0',board,0);
  PawnChess(3,5,'1',board,1);

  int x1,y1,x2,y2;

  for(;;)
  {
   board.draw();
   std::cin>>x1>>y1>>x2>>y2;
   std::system("clear");
   board.onBoard(x1,y1,x2,y2);
  }
}
