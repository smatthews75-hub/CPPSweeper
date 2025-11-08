# CPPSweeper
CLI Minesweeper executable with C++. Made with [PDCurses by Bill Gray](https://github.com/Bill-Gray/PDCursesMod)
---
Something fun to learn C++ and BFS/DFS algorithms. This project is built in Windows OS, unfortunately support for other OS is yet to be developed. This project is open source and free to use. You can clone and learn from the code as you wish or smth.
## How to Compile
Compilation requires `g++` compiler installed on your terminal. The `g++` compiler version used for development is `g++.exe (Rev8, Built by MSYS2 project) 15.2.0` but earlier version may be usable. To compile this project, run the following command on your terminal:
```bash
g++ -std=c++17 -Iinclude -Isrc/headers src/main.cpp -Llib -static lib/pdcurses.a lib/panel.a -lwinmm -o build/minesweeper.exe
```
---
## How to Run
The executable will be created in the `build` folder. To run the executable, use the command:
```bash
./build/minesweeper.exe
```