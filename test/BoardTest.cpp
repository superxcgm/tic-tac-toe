//
// Created by Yujia Li on 2020/5/5.
//
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ostream>
#include <array>

class Board {
public:
    Board() {
        int index = 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = (index++) + '0';
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Board &board) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                os << " " << board.data[i][j];
                if (j != 3 - 1) {
                    os << " |";
                } else {
                    os << "\n";
                }
            }
        }
        return os;
    }

    void submit(int pos) {
        data[(pos - 1) / 3][(pos - 1) % 3] = 'X';
    }

private:
    std::array<std::array<char, 3>, 3> data;
};

TEST(ABoard, DisplayInitialBoard) {
    Board board;
    std::ostringstream os;

    os << board;

    auto got = os.str();
    std::string want = std::string(" 1 | 2 | 3\n") +
                       " 4 | 5 | 6\n" +
                       " 7 | 8 | 9\n";

    ASSERT_THAT(got, testing::StrEq(want));
}

TEST(ABoard, DisplayChangedBoardWhenPlayerSubmit) {
    Board board;
    std::ostringstream os;

    board.submit(4);
    os << board;

    auto got = os.str();
    std::string want = std::string(" 1 | 2 | 3\n") +
                       " X | 5 | 6\n" +
                       " 7 | 8 | 9\n";

    ASSERT_THAT(got, testing::StrEq(want));
}