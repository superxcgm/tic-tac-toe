//
// Created by Yujia Li on 2020/5/5.
//

#include <Coordinate.h>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Eq;

TEST(ACoordinate, ConverFromPosCorrectly) {
    auto c = Coordinate::fromPos(4, 3);

    ASSERT_THAT(c.x, Eq(0));
    ASSERT_THAT(c.y, Eq(1));
}
