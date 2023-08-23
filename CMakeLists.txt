cmake_minimum_required(VERSION 3.25)
project(planters)

set(CMAKE_CXX_STANDARD 17)

add_executable(planters planters.cpp testutil.h testutil.cpp plantermgr.cpp plantermgr.h Box.cpp Box.h BoxTree.cpp BoxTree.h BoxList.cpp BoxList.h)
