//
// Created by Yujia Li on 2020/5/5.
//

#ifndef TIC_TAC_TOE_COORDINATE_H
#define TIC_TAC_TOE_COORDINATE_H


struct Coordinate {
    Coordinate(int x, int y) : x(x), y(y) {}

    int x;
    int y;

    static Coordinate fromPos(int pos, int col) {
        return Coordinate((pos - 1) % col, (pos - 1) / col);
    }

    Coordinate left() {
        return Coordinate(x - 1, y);
    }
};


#endif //TIC_TAC_TOE_COORDINATE_H
