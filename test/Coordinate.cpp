//
// Created by Yujia Li on 2020/5/5.
//

#include <Coordinate.h>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(ACoordinate, ConverFromPosCorrectly) {
    Coordinate c(4, 3);

    ASSERT_THAT(c.x, testing::Eq(0));
    ASSERT_THAT(c.y, testing::Eq(1));
}