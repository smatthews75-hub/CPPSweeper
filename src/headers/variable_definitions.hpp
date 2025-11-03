// GLOBAL VARIABLE DEFINITIONS ARE HERE !!!

#pragma once

#define PDC_STATIC // somewhat important for include curses.h
#define PDC_RGB // somewhat important as well
#include <curses.h>
#include <panel.h>

#include <string>
#include <vector>
#include <cctype>

// a function called from int main(void) to init and build PDCurses environment
void initialize_cursed_environment() {
    initscr();
    start_color();
    keypad(stdscr, TRUE); // enable reading special keys
    refresh(); // Ensure stdscr is drawn
    cbreak(); // turns off line buffering, any key press went straight into program input
    noecho(); // disable echoing typed characters to the screen -- full control of output

    // color initializations
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
}
// custom data structure to coordinate PDCurses based display
struct WINPAN { // aka WindowPanel
    WINDOW* window_; PANEL* panel_;
    int line_height, coll_width;
    int text_attr = A_NORMAL; // font style attribute
    short color_pair_id = COLOR_PAIR(0); // color pair id
    // initializer aka CONSTRUCTOR
    WINPAN(const int &h, const int &w, const int &y, const int &x) {
        window_ = newwin(h, w, y, x);
        panel_ = new_panel(window_);
        line_height = h; coll_width = w;}
    // deleter aka DECONSTRUCTOR
    ~WINPAN() {hide_panel(panel_); del_panel(panel_); delwin(window_);}
    
    // quick show hide functions for this WindowPanel
    void show() {show_panel(panel_);}
    void hide() {hide_panel(panel_);}
    // get input from this WindowPanel
    int input() {return wgetch(window_);}
    
    // set the STYLE of this WindowPanel
    void set_style(const short &color_id, const int &attr_flags) {
        color_pair_id = COLOR_PAIR(color_id);
        text_attr = attr_flags;}
    // apply the set styles
    void apply_style() {wattron(window_, color_pair_id | text_attr);}
    // clear the set styles
    void clear_style() {wattroff(window_, color_pair_id | text_attr);}
    // print into this window with s t y l e
    void wprint(const int &line_, const int &coll_, const std::string &message) {
        apply_style(); mvwprintw(window_, line_, coll_, "%s", message.c_str()); clear_style();}
    
    void draw_border(chtype ls = '|', chtype rs = '|', chtype ts = '-',
    chtype bs = '-', chtype tl = '+', chtype tr = '+', chtype bl = '+', chtype br = '+') {
        apply_style(); wborder(window_, ls, rs, ts, bs, tl, tr, bl, br); clear_style();
    }
    // clear the window's internal buffer
    void wclear() {werase(window_);}
};

// GAMEPLAY VARIABLES
struct CELL {
    bool isMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};
std::vector<std::vector<CELL>> mine_field;