// #pragma once

// #include <vector>

// struct CELL {
//     bool isMine = false;
//     bool isRevealed = false;
//     int adjacentMines = 0;
// };

// std::vector<std::vector<CELL>> mine_field;

#pragma once

#include <string>

struct Cell {
    bool isMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

inline std::string getTestMessage() {
    return "Hello from variable_definitions!";
}