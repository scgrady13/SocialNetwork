cmake_minimum_required(VERSION 3.12)
project(program5)

set(CMAKE_CXX_STANDARD 14)

add_executable(program5 main.cpp LinkList.cpp LinkList.h Friend.h Friend.cpp)
