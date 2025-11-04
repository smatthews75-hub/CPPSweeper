// DEFINED STAGES OF THE GAME
#pragma once
#include "function_definitions.hpp"

// #1 FIRST WINDOW IS A WELCOME SCREEN !!!
void welcome_screen() {
    // START with getting the user used to keyboard input
    WINDOW* press_enter_scr = newwin(10, 30, 0, 0); box(press_enter_scr,0,0);
    mvwprintw(press_enter_scr, 4, 2, "Press any key to continue.");
    wrefresh(press_enter_scr); wgetch(press_enter_scr); delwin(press_enter_scr);
    // game intro screen
    WINDOW* wel_scr = newwin(10,30,0,0); box(wel_scr, 0, 0);
    mvwprintw(wel_scr, 1, 1, "#######1____=__=____1#######");
    mvwprintw(wel_scr, 2, 1, "###1                    1###");
    mvwprintw(wel_scr, 3, 1, "#1   << MINESWEEPER >>    1#");
    mvwprintw(wel_scr, 5, 1, "Made with C++ with a pint of");
    mvwprintw(wel_scr, 6, 1, "  blood, sweat, and tears.  ");
    mvwprintw(wel_scr, 8, 1, "(powered by pain and agony.)");
    // display the screen, get input to continue, del and exit
    wrefresh(wel_scr); wgetch(press_enter_scr); delwin(wel_scr); return;
}

// HELPER FUNCTION FOR THE prompt_window_setup()
bool confirm_preview(const int &row_, const int &col_) {
    WINPAN preview_scr(row_, col_ * 3, 0, 0, true); // * 3 because the minefields are gonna be printed with 3 chars each
    preview_scr.set_style(C_RED, A_BOLD);
    preview_scr.wsprint(1, 1, "This will be the size of the minefield");
    preview_scr.wsprint(2, 1, "ENTER to CONFIRM. or any key to cancel");
    update_panels(); doupdate();
    int ch = preview_scr.input(); // prompt for input
    return (ch == '\n' || ch == '\r' || ch == KEY_ENTER) ? true : false;
}

// #2 PROMPT THE WIDTH AND LENGTH OF THE WINDOW
void prompt_minefield_assignment(int &y, int &x) {
    WINPAN prompt_scr(LINES - 1, COLS - 1, 0, 0, true);
    prompt_scr.set_style(C_GOLD, A_BOLD);
    prompt_scr.wsprint(LINES/2-2, 1, "<<< MINE FIELD  AREA ASSIGNMENT >>>");
    prompt_scr.wprint(LINES/2-1, 1, "How much do you want to work with ?");
    update_panels(); doupdate();
    int width, length;
    while (true) { // prompt until a confirmed valid length and width
        width = prompt_int(prompt_scr, LINES/2+1, 1,  "Enter width  : ", 15, 50);
        length = prompt_int(prompt_scr, LINES/2+2, 1, "Enter length : ", 15, 50);
         // ensure y vertical is less than x horizontal
        y = std::min(width, length); // remember y and x are reference
        x = std::max(width, length); // to global minefield_x and _y !
        if (confirm_preview(y, x)) {return;}
    }
}
