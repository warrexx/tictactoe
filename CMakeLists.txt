cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(tictactoe src/main.cpp src/Game.cpp src/Player.cpp src/Board.cpp )