//
// Created by Yujia Li on 2020/5/5.
//

#include "Board.h"

Board::Board() {
    int index = 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] = (index++) + '0';
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    for (int i = 0; i < Board::row; ++i) {
        for (int j = 0; j < Board::col; ++j) {
            os << " " << board.data[i][j];
            if (j != Board::col - 1) {
                os << " |";
            } else {
                os << "\n";
            }
        }
    }
    return os;
}

void Board::submit(Player player, int pos) {
    char sign;
    if (player == Player::_1) {
        sign = 'X';
    } else {
        sign = 'O';
    }
    data[(pos - 1) / col][(pos - 1) % col] = sign;
}