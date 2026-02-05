# CONFIGURE CMAKE : cmake -S . -B build
# BUILD : cmake --build build

# tells CMAKE to read this with the stated version
cmake_minimum_required(VERSION 3.11)

# declare the project
project(
    CPPSWEEPER
    VERSION 1.0
    LANGUAGES CXX
)

# declare the exe target named minesweeper
add_executable(minesweeper
    src/main.cpp # target's source code
)

# tell whichever compiler to use the specified C++ version
set_target_properties(minesweeper PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

# declare path to include in compiler
target_include_directories(minesweeper PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/headers
)

# declare path to link libs in compiler
target_link_libraries(minesweeper PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/pdcurses.a
    ${PROJECT_SOURCE_DIR}/lib/panel.a
    winmm
)

# that flag to static link libs so the target exe is independent
target_link_options(minesweeper PRIVATE -static)