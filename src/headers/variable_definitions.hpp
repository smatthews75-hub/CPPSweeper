// GLOBAL VARIABLE DEFINITIONS ARE HERE !!!

#pragma once

#include <string>
#include <vector>

struct CELL {
    bool isMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

std::vector<std::vector<CELL>> mine_field;

std::string getTestMessage() {
    return "Hello from variable_definitions!";
}