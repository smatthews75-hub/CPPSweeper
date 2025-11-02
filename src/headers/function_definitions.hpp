// #pragma once

// #include "variable_definitions.hpp"

// #define PDC_STATIC
// #define PDC_RGB
// #include <curses.h>

#pragma once

#define PDC_STATIC
#define PDC_RGB
#include <curses.h>
#include "variable_definitions.hpp"

void drawTestMessage(WINDOW* win) {
    std::string msg = getTestMessage();
    // std::string msg = "HELP ME WITH THIS NIGHTMARE";
    mvwprintw(win, 1, 1, "%s", msg.c_str());
}