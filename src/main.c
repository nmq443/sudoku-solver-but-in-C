#include <stdio.h>
#include "solver.h"
#include "print.h"

int main(int argc, char **argv)
{
    printf("Sudoku solver written in C!\n");

    int board[BOARD_SIZE][BOARD_SIZE] =
    {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    printf("Before solving: \n");
    print_board(board);

    if (!solve(board, 0, 0))
    {
        printf("\nBoard unsolvable!");
    }
    return 0;
}
