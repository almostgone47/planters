cmake_minimum_required(VERSION 3.25)
project(planters)

set(CMAKE_CXX_STANDARD 17)

add_executable(planters
        ./src/planters.cpp
        ./src/plantermgr.cpp
        ./include/plantermgr.h
        ./src/Box.cpp
        ./include/Box.h
        ./src/BoxTree.cpp
        ./include/BoxTree.h
        ./src/BoxList.cpp
        ./include/BoxList.h
        )

# Include Google Test CMakeLists.txt
add_subdirectory(googletest)

# Create a target for your tests executable
add_executable(tests
        ./tests/box_tests.cpp
        ./tests/boxtree_tests.cpp
        ./tests/boxlist_tests.cpp
        ./tests/plantermgr_tests.cpp
        )

# Link against Google Test and Google Test Main
target_link_libraries(tests gtest gtest_main)

# Include Google Test headers
target_include_directories(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/googletest/googletest/include
        ${CMAKE_SOURCE_DIR}/googletest/googlemock/include
        )

# Add a test that runs your tests executable
add_test(NAME tests COMMAND tests)
