// DEFINED STAGES OF THE GAME
#pragma once
#include "function_definitions.hpp"

void welcome_screen(void) {
    // START with getting the user used to keyboard input
    WINDOW* press_enter_scr = newwin(10, 30, 0, 0); box(press_enter_scr,0,0);
    mvwprintw(press_enter_scr, 4, 2, "Press any key to continue.");
    wrefresh(press_enter_scr); getch(); delwin(press_enter_scr);

    // game screen
    WINDOW* wel_scr = newwin(10,30,0,0); box(wel_scr, 0, 0);
    mvwprintw(wel_scr, 1, 1, "#######1____=__=____1#######");
    mvwprintw(wel_scr, 2, 1, "###1                    1###");
    mvwprintw(wel_scr, 3, 1, "#1   << MINESWEEPER >>    1#");
    mvwprintw(wel_scr, 5, 1, "Made with C++ with a pint of");
    mvwprintw(wel_scr, 6, 1, "  blood, sweat, and tears.  ");
    mvwprintw(wel_scr, 8, 1, "(powered by pain and agony.)");

    wrefresh(wel_scr); getch(); delwin(wel_scr); return;
}
