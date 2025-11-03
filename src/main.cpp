// MINESWEEPER CLI by StephenSQ made with PDCursesMod by Bill Gray
// cd "C:\Users\locke\DATA\Projects\cpp_with_curses\CPPSweeper"
// g++ -std=c++17 -Iinclude -Isrc/headers src/main.cpp -Llib -static lib/pdcurses.a lib/panel.a -lwinmm -o build/minesweeper.exe

#ifdef _WIN32
#define main main
#endif

// #include "headers/function_definitions.hpp"
#include "headers/gamestages.hpp"

int main(void) {
    initialize_cursed_environment(); // initscr() and start_color() is called here 

    welcome_screen();
    prompt_minefield_assignment();
    // WINDOW* win = newwin(40, 40, 0, 0); // Move to top-left
    // box(win, 0, 0);
    // drawTestMessage(win);
    // std::string msg_ = "BRUH";
    // mvwprintw(win, 2, 1, "%s", msg_.c_str()); // Avoid overwrite
    // wrefresh(win);

    getch();
    endwin(); // the end of it all, clean up and exit Curses mode
    return 0;
}
