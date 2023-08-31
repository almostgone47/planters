//
// Created by Jeremiah Barro on 31/8/2023.
//

#include <gtest/gtest.h>
#include <chrono>
#include <iostream>

class PerformanceGradingTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(PerformanceGradingTest, GradePerformance) {
    std::string command = "../../src/planters large.txt";

    std::string output;

    auto startTime = std::chrono::high_resolution_clock::now();

    FILE* pipe = popen(command.c_str(), "r");
    if (pipe) {
        char buffer[128];
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != nullptr)
                output += buffer;
        }
        pclose(pipe);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    int points = 0;

    if (elapsedTime < 250) {
        points = 7;
    } else if (elapsedTime < 500) {
        points = 6;
    } else if (elapsedTime < 1000) {
        points = 3;
    } else if (elapsedTime < 2000) {
        points = 2;
    } else if (elapsedTime < 3000) {
        points = 1;
    } else {
        points = 0;
    }

    std::cout << "Execution time: " << elapsedTime << " ms" << std::endl;
    std::cout << "Points: " << points << std::endl;

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
