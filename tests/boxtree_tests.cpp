//
// Created by Jeremiah Barro on 30/8/2023.
//

#include <gtest/gtest.h>
#include "../include/Box.h"
#include "../include/BoxList.h"
#include "../include/BoxTree.h"

class BoxTreeTest : public testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST(BoxTreeTest, TestInsertAndRemove) {
    BoxTree bt;

    // Insertion and removal values
    int numValues = 6;
    int values[] = {27, 24, 181, 100, 189, 19};
    int numRemoveValues = 3;
    int removeValues[] = {19, 100, 24};

    for (int i = 0; i < numValues; i++) {
        Box *box = new Box(values[i], "one");
        bt.insert(box);
    }

    for (int i = 0; i < numRemoveValues; i++) {
        bt.remove(removeValues[i]);
    }

    EXPECT_EQ(bt.getTotalNodes(), numValues - numRemoveValues);

    // After removing 24 and 100
    BoxList rangeList = bt.getRange(24, 181);
    EXPECT_EQ(rangeList.getSize(), 2);
}

TEST(BoxTreeTest, TestGetRangeTraversal) {
    BoxTree bt;

    Box *boxA = new Box(50, "A");
    Box *boxB = new Box(25, "B");
    Box *boxC = new Box(75, "C");
    Box *boxD = new Box(10, "D");
    Box *boxE = new Box(30, "E");
    Box *boxF = new Box(60, "F");
    Box *boxG = new Box(80, "G");

    bt.insert(boxA);
    bt.insert(boxB);
    bt.insert(boxC);
    bt.insert(boxD);
    bt.insert(boxE);
    bt.insert(boxF);
    bt.insert(boxG);

    BoxList rangeList = bt.getRange(30, 60);

    EXPECT_EQ(rangeList.getSize(), 3);
}