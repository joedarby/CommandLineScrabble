cmake_minimum_required(VERSION 3.6)
project(CommandLineScrabble)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp player.cpp player.h playerTileSet.cpp playerTileSet.h tile.cpp tile.h letterBag.cpp letterBag.h word.cpp word.h game.cpp game.h valuer.cpp valuer.h board.cpp board.h boardPlacement.cpp boardPlacement.h)
add_executable(CommandLineScrabble ${SOURCE_FILES})