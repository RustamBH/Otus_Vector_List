cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(MyVector	MyVector.cpp MyVector.h)
set_target_properties(MyVector PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(MyList MyList.cpp MyList.h)
set_target_properties(MyList PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)