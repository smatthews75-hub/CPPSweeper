// GLOBAL VARIABLE DEFINITIONS ARE HERE !!!

#pragma once

#include <string>
#include <vector>
#include <cctype>

struct CELL {
    bool isMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

std::vector<std::vector<CELL>> mine_field;