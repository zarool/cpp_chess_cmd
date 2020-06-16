cmake_minimum_required(VERSION 3.16)
project(chess_cmd)

set(CMAKE_CXX_STANDARD 14)

add_executable(chess_cmd main.cpp board.cpp board.h Piece.h pieces/Type.cpp pieces/Type.h)