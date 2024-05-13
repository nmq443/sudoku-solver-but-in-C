cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

project(sudoku-solver VERSION 1.0)

add_library(solver src/solver.c src/print.c src/board_generator.c)
add_library(printer src/print.c src/solver.c src/board_generator.c)
add_library(board_generator src/board_generator.c src/print.c src/solver.c)

target_include_directories(
    solver
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(
    printer 
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(
    board_generator 
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(main src/main.c)

target_link_libraries(
    main 
    PUBLIC 
    solver
)

target_link_libraries(
    main 
    PUBLIC 
    printer
)

target_link_libraries(
    main
    PUBLIC 
    board_generator
)
