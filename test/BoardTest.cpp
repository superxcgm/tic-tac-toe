//
// Created by Yujia Li on 2020/5/5.
//
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ostream>
#include <Board.h>

class ABoard: public testing::Test {
public:
    Board board;
    std::ostringstream os;
};

TEST_F(ABoard, DisplayInitialBoard) {
    os << board;

    auto got = os.str();
    std::string want = std::string(" 1 | 2 | 3\n") +
                       " 4 | 5 | 6\n" +
                       " 7 | 8 | 9\n";

    ASSERT_THAT(got, testing::StrEq(want));
}

TEST_F(ABoard, DisplayChangedBoardWhenPlayer1Submit) {
    board.submit(Player::_1, 4);
    os << board;

    auto got = os.str();
    std::string want = std::string(" 1 | 2 | 3\n") +
                       " X | 5 | 6\n" +
                       " 7 | 8 | 9\n";

    ASSERT_THAT(got, testing::StrEq(want));
}

TEST_F(ABoard, DisplayChangedBoardWhenPlayer2Submit) {
    board.submit(Player::_2, 4);
    os << board;

    auto got = os.str();
    std::string want = std::string(" 1 | 2 | 3\n") +
                       " O | 5 | 6\n" +
                       " 7 | 8 | 9\n";

    ASSERT_THAT(got, testing::StrEq(want));
}

TEST_F(ABoard, ShouldTerminateWhen3SameSignAtOneHorizontalLine) {
    board.submit(Player::_1, 1);
    board.submit(Player::_1, 2);
    board.submit(Player::_1, 3);

    ASSERT_FALSE(board);
}