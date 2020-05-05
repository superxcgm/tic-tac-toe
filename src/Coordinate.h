//
// Created by Yujia Li on 2020/5/5.
//

#ifndef TIC_TAC_TOE_COORDINATE_H
#define TIC_TAC_TOE_COORDINATE_H


struct Coordinate {
    Coordinate(int pos, int col) {
        y = (pos - 1) / col;
        x = (pos - 1) % col;
    }
    int x;
    int y;
};


#endif //TIC_TAC_TOE_COORDINATE_H
