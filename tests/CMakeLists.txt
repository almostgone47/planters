cmake_minimum_required(VERSION 3.25)
project(tests)
# Include Google Test
add_subdirectory(../googletest ${CMAKE_BINARY_DIR}/googletest)

# Add your test source files
set(TEST_SOURCES
        box_tests.cpp
        boxlist_tests.cpp
        boxtree_tests.cpp
        plantermgr_tests.cpp
        ../src/Box.cpp
        ../src/BoxList.cpp
        ../src/BoxTree.cpp
        ../src/PlanterMgr.cpp
        performance_tests.cpp)


# Create an executable for tests
add_executable(tests ${TEST_SOURCES})

# Link against Google Test libraries
target_link_libraries(tests PRIVATE gtest gtest_main)

# Add include directories
target_include_directories(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/googletest/googletest/include
        )

# Optional: Define custom target for running tests
add_custom_target(run_tests
        COMMAND tests
        DEPENDS tests
        )
