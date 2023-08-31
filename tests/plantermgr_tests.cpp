//
// Created by Jeremiah Barro on 30/8/2023.
//

#include <gtest/gtest.h>
#include "../include/plantermgr.h"

class PlanterMgrTest : public testing::Test {
protected:
    void SetUp() override {
        pm = new PlanterMgr();
        pm->plant(1, "Rose");
        pm->plant(2, "Rose");
        pm->plant(3, "Rose");
    }

    void TearDown() override {
        delete pm;
    }

    PlanterMgr* pm;
};

TEST_F(PlanterMgrTest, TestPlant) {
    testing::internal::CaptureStdout();

    pm->plant(4, "Rose");

    std::string actualOutput = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "Planting Rose in box 4\n";
    EXPECT_EQ(expectedOutput, actualOutput);
}

TEST_F(PlanterMgrTest, TestHarvest) {
    testing::internal::CaptureStdout();

    pm->harvest("Rose", 1, 2);

    std::string actualOutput = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "Harvesting Rose plants from boxes 1 to 2. \nThe following boxes will be harvested: 1 2 \n";
    EXPECT_EQ(expectedOutput, actualOutput);
}

TEST_F(PlanterMgrTest, TestPrune) {
    testing::internal::CaptureStdout();

    pm->prune(1);

    std::string actualOutput = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "Pruning box number 1.\n";
    EXPECT_EQ(expectedOutput, actualOutput);
}
