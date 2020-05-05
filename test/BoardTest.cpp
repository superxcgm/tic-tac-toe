//
// Created by Yujia Li on 2020/5/5.
//
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ostream>

class Board {
public:
    friend std::ostream &operator<<(std::ostream &os, const Board &board) {
        os << (std::string(" 1 | 2 | 3\n") +
              " 4 | 5 | 6\n" +
              " 7 | 8 | 9\n");
        return os;
    }
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