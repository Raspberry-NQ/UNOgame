cmake_minimum_required(VERSION 3.23)
project(UNOgame)

set(CMAKE_CXX_STANDARD 17)

add_executable(UNOgame main.cpp)
set(CMAKE_EXE_LINKER_FLAGS -static)