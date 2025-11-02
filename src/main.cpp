// MINESWEEPER CLI by StephenSQ made with PDCursesMod by Bill Gray
// g++ -std=c++17 -Iinclude -Llib -static src/main.cpp lib/pdcurses.a lib/panel.a -lwinmm -o build/minesweeper.exe

#ifdef _WIN32
#define main main
#endif

#include <curses.h>
#include <panel.h>

int main() {
    initscr();            // Start curses mode
    cbreak();             // Disable line buffering
    noecho();             // Don't echo keypresses
    keypad(stdscr, TRUE); // Enable arrow keys

    start_color();        // Enable color
    init_pair(1, COLOR_RED, COLOR_BLACK);

    WINDOW* win = newwin(5, 20, 3, 3);     // Create a window
    PANEL* pan = new_panel(win);          // Attach panel to window

    wbkgd(win, COLOR_PAIR(1));            // Set background color
    box(win, 0, 0);                        // Draw border
    mvwprintw(win, 2, 2, "Hello, Stephen!");
    update_panels();                      // Refresh panel stack
    doupdate();                           // Push to screen

    getch();                              // Wait for key press
    endwin();                             // End curses mode
    return 0;
}