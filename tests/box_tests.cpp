//
// Created by Jeremiah Barro on 29/8/2023.
//
#include <gtest/gtest.h>
#include "../include/Box.h"

class BoxTest : public testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(BoxTest, DefaultConstructor) {
    Box box;
    EXPECT_EQ(box.getNum(), 0);
    EXPECT_STREQ(box.getPlantName(), "");
}

TEST_F(BoxTest, ParametrizedConstructor) {
    Box box(1, "Plant");
    EXPECT_EQ(box.getNum(), 1);
    EXPECT_STREQ(box.getPlantName(), "Plant");
}
