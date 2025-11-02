// FUNCTION DEFINITIONS ARE HERE !!!

#pragma once

#define PDC_STATIC // somewhat important for include curses.h
#define PDC_RGB // somewhat important as well
#include <curses.h>
#include <panel.h>
#include "variable_definitions.hpp"

void drawTestMessage(WINDOW* win) {
    std::string msg = getTestMessage();
    // std::string msg = "HELP ME WITH THIS NIGHTMARE";
    mvwprintw(win, 1, 1, "%s", msg.c_str());
}