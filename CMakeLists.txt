cmake_minimum_required(VERSION 3.6)
project(CommandLineScrabble)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Player.cpp Player.h PlayerTileSet.cpp PlayerTileSet.h LetterBag.cpp LetterBag.h Game.cpp Game.h Board.cpp Board.h BoardPlacement.cpp BoardPlacement.h TileSet.cpp TileSet.h)
add_executable(CommandLineScrabble ${SOURCE_FILES})