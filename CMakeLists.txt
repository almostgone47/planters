cmake_minimum_required(VERSION 3.25)
project(planters)

set(CMAKE_CXX_STANDARD 17)

add_executable(planters src/planters.cpp testutil.h testutil.cpp src/plantermgr.cpp include/plantermgr.h src/Box.cpp include/Box.h src/BoxTree.cpp include/BoxTree.h src/BoxList.cpp include/BoxList.h tests/box_tests.cpp tests/boxtree_tests.cpp tests/boxlist_tests.cpp tests/plantermgr_tests.cpp)

# Include Google Test CMakeLists.txt
add_subdirectory(googletest)

# Link against Google Test
target_link_libraries(planters gtest gtest_main)

include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)
