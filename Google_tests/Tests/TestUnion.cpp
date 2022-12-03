//
// Created by Amo on 2022/11/28.
//

#include "gtest/gtest.h"
#include "../../Union/QuickUnion.h"
#include "../../Union/QuickUnion.cpp"

TEST(TestUnion, BasicTest) {
    QuickUnion quickUnion(10);

    quickUnion.connect(1, 2);
    quickUnion.connect(7, 8);
    quickUnion.connect(9, 8);

    ASSERT_TRUE(quickUnion.isConnect(7, 9));
    ASSERT_FALSE(quickUnion.isConnect(5, 6));
}