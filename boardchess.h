#ifndef BOARDCHESS_H
#define BOARDCHESS_H


#include "basechess.h"
#include <string>

#include <vector>

struct BaseChess;

struct BoardChess
{
    std::vector<std::vector<BaseChess*>> board;
    BoardChess();
    bool onBoard(int,int,int,int);
    void draw();
    void start();
    bool color=1;//Определение текущей ходящей стороны
    ~BoardChess(){};
};

#endif // BOARDCHESS_H
