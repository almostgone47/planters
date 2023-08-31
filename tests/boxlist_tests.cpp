//
// Created by Jeremiah Barro on 30/8/2023.
//

#include <gtest/gtest.h>
#include "../include/BoxList.h"

class BoxListTest : public testing::Test {
protected:
    void SetUp() override {
        bl = new BoxList();
    }

    void TearDown() override {
        delete bl;
    }

    BoxList* bl;
};

TEST_F(BoxListTest, TestInsertAtTail) {
    int numBoxes = 5;
    for (int i = 0; i < numBoxes; i++) {
        Box* box = new Box(i, "test");
        bl->insertAtTail(box);
    }

    EXPECT_EQ(bl->getSize(), numBoxes);

    bl->startIterating();
    for (int i = 0; i < numBoxes; i++) {
        EXPECT_TRUE(bl->hasNextBox());
        const Box* box = bl->getNextBox();
        EXPECT_EQ(box->getNum(), i);
    }

    EXPECT_FALSE(bl->hasNextBox());
}

TEST_F(BoxListTest, TestCopyConstructor) {
    int numBoxes = 3;
    for (int i = 0; i < numBoxes; i++) {
        Box* box = new Box(i, "test");
        bl->insertAtTail(box);
    }

    BoxList blCopy(*bl);

    EXPECT_EQ(blCopy.getSize(), numBoxes);

    blCopy.startIterating();
    for (int i = 0; i < numBoxes; i++) {
        EXPECT_TRUE(blCopy.hasNextBox());
        const Box* box = blCopy.getNextBox();
        EXPECT_EQ(box->getNum(), i);
    }

    EXPECT_FALSE(blCopy.hasNextBox());
}

TEST_F(BoxListTest, TestGetSize) {
    EXPECT_EQ(bl->getSize(), 0);

    int numBoxes = 5;
    for (int i = 0; i < numBoxes; i++) {
    Box* box = new Box(i, "test");
    bl->insertAtTail(box);
    }

    EXPECT_EQ(bl->getSize(), numBoxes);
}

