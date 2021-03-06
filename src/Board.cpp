//
// Created by Yujia Li on 2020/5/5.
//

#include "Board.h"
#include "Coordinate.h"

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
    updateBoard(pos, getPlayerSign(player));
}

char Board::getPlayerSign(Player player) {
    if (player == Player::_1) {
        return 'X';
    } else {
        return 'O';
    }
}

void Board::updateBoard(int pos, char sign) {
    lastPos = pos;
    auto c = Coordinate::fromPos(pos, Board::col);
    data[c.y][c.x] = sign;
}

bool Board::isCoordinateValid(const Coordinate &c) const {
    if (c.x < 0 || c.x >= col) {
        return false;
    }
    if (c.y < 0 || c.y >= row) {
        return false;
    }
    return true;
}

int Board::countSide(Coordinate current, Coordinate (*getNext)(const Coordinate &), char sign) const {
    int cnt = 0;
    while (true) {
        auto next = getNext(current);
        if (!isCoordinateValid(next)) {
            break;
        }
        if (data[next.y][next.x] != sign) {
            break;
        }
        current = next;
        cnt++;
    }
    return cnt;
}

Board::operator bool() const {
    if (lastPos == NotAPos) return true;

    int cnt = 1;
    auto last = Coordinate::fromPos(lastPos, col);
    auto lastSign = data[last.y][last.x];

    // TODO: duplicate code
    cnt += countSide(last, [](const Coordinate &current) { return current.left(); }, lastSign);
    cnt += countSide(last, [](const Coordinate &current) { return current.right(); }, lastSign);

    if (cnt >= 3) {
        return false;
    }

    cnt = 1;
    cnt += countSide(last, [](const Coordinate &current) { return current.up(); }, lastSign);
    cnt += countSide(last, [](const Coordinate &current) { return current.down(); }, lastSign);
    if (cnt >= 3) {
        return false;
    }

    cnt = 1;
    cnt += countSide(last, [](const Coordinate &current) { return current.upLeft(); }, lastSign);
    cnt += countSide(last, [](const Coordinate &current) { return current.downRight(); }, lastSign);
    if (cnt >= 3) {
        return false;
    }

    cnt = 1;
    cnt += countSide(last, [](const Coordinate &current) { return current.upRight(); }, lastSign);
    cnt += countSide(last, [](const Coordinate &current) { return current.downLeft(); }, lastSign);
    if (cnt >= 3) {
        return false;
    }
    return true;
}
