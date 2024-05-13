#include <stdio.h>
#include <stdlib.h>
#include "solver.h"
#include "print.h"
#include "board_generator.h"

int main(int argc, char **argv)
{
    printf("Sudoku solver written in C!\n");
    
    printf("\nInitialize a new board!");
    int **board = NULL;
    board = init_board();

    if (!board)
    {
        printf("Can't initialize a board!\n");
        return -1;
    } 

    int ***p_board = NULL;
    p_board = &board;

    if (!solve(p_board, 0, 0))
    {
        printf("\nBoard unsolvable!");
    } else 
    {
        print_board(board);
    }

    free(board);
    return 0;
}
