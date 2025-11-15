# CPPSweeper
CLI Minesweeper executable with C++. Made with [PDCursesMod by Bill Gray](https://github.com/Bill-Gray/PDCursesMod)
---
Something fun to learn C++ and BFS/DFS algorithms. This project is built for Windows OS, unfortunately support for other OS is yet to be developed. This project is open source and free to use. You can clone and learn from the code as you wish or smth.  
```
┌─────────────────────────────────────────────┐  
│ 1 [x] 1     1  #  1        1 [x] 2 [x] #  # │ A preview of this minesweeper CLI game :  
│ 2  2  1     1 [x] 1        1  1  2  2  #  # │  
│[x] 1        1  1  1              1  2 [x] # │ Controls will be keyboard based such as  
│ 1  2  1  1              1  1  1  2 [x] 3  1 │  
│    1 [x] 1              1 [x] 1  2 [x] 2    │ WASD to move cursor across the grids, 
│    1  1  1              1  1  1  1  1  1    │ F to flag/unflag a grid,  
│                                             │ Enter to reveal a grid, and so on.  
│                            1  1  1          │   
│                   1  1  1  1 [x] 1          │ A manual on how to play classic minesweeper  
│                   1 [x] 1  1  1  1          │ is available in game though not verbose.  
│       1  1  1     1  1  1                   │  
│       1 [x] 1                               │  
│       1  1  1                               │  
│             1  2  2  1                      │  
│             1 [x][x] 1                      │  
└─────────────────────────────────────────────┘ 
``` 
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
---
## tasks.json
this repository contains a `.vscode` directory to help you set up build and run tasks if you are using VSCode as your IDE. You can find the `tasks.json` file in the `.vscode` directory. The tasks are already set up to compile and run the project using the commands mentioned above.  
> a task named `Compile C++` can be set to a keybind in your `keybindings.json` to automate compiling the project.with one press of a button.

> a task named `Compile n Run C++` can be set to a keybind as well to automate running the project for quick tests.
---