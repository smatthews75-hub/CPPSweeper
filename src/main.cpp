// MINESWEEPER CLI by StephenSQ made with PDCursesMod by Bill Gray
// g++ -std=c++17 -Iinclude -Isrc/headers src/main.cpp -Llib -static lib/pdcurses.a lib/panel.a -lwinmm -o build/minesweeper.exe

#ifdef _WIN32
#define main main
#endif

#include "headers/function_definitions.hpp"
#include <curses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh(); // Ensure stdscr is drawn

    WINDOW* win = newwin(10, 40, 0, 0); // Move to top-left
    box(win, 0, 0);
    drawTestMessage(win);
    std::string msg_ = "BRUH";
    mvwprintw(win, 2, 1, "%s", msg_.c_str()); // Avoid overwrite
    wrefresh(win);

    getch();
    endwin();
    return 0;
}
