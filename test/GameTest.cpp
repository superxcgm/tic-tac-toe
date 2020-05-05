//
// Created by Yujia Li on 2020/5/5.
//

#include <Game.h>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(AGame, ShouldExitWhenOnePlayerWin) {
    std::istringstream is("1\n4\n2\n5\n3\n");
    Game game(is);

    auto got = game.start();

    ASSERT_THAT(got, testing::StrEq("Player1 Win"));
}