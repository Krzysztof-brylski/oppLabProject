cmake_minimum_required(VERSION 3.23)
project(oppLabProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(oppLabProject main.cpp view/menu.cpp sheet/sheet.cpp cell/intCell.cpp)
