//
// Created by Yujia Li on 2020/5/5.
//

#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include "Board.h"


class Game {
public:
    Game(std::istream &is) : is(is) {}

    std::string start();

private:
    Board board;
    std::istream &is;
    void printBoard();
};


#endif //TIC_TAC_TOE_GAME_H
