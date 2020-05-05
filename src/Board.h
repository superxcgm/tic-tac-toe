//
// Created by Yujia Li on 2020/5/5.
//

#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <iostream>
#include <array>
#include "Player.h"

class Board {
public:
    Board();

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

    void submit(Player player, int pos);

private:
    char getPlayerSign(Player player);
    void updateBoard(int pos, char sign);
    static constexpr int row = 3;
    static constexpr int col = 3;
    std::array<std::array<char, col>, row> data;
};


#endif //TIC_TAC_TOE_BOARD_H
