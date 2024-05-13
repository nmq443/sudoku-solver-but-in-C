#include "solver.h"

/*
int **init_board()
{
    printf("Initialize a new sudoku board!\n");
    int **board = (int**) malloc (BOARD_SIZE * sizeof(int));
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        board[row] = (int*) malloc (BOARD_SIZE * sizeof(int));
    }
    return board;
}
*/

int solve(int board[][BOARD_SIZE], int row, int col)
{
    if (col == 9)
    {
        if (row == 8)
        {
            printf("Solved: \n");
            print_board(board);
            return 1;
        }
        col = 0;
        ++row;
    }
    
    if (board[row][col] > 0)
    {
        return solve(board, row, col + 1);
    }
    for (int num = 1; num <= 9; ++num)
    {
        if (is_valid(board, num, row, col))
        {
            if (finished(board))
            {
                return 1;
            }

            board[row][col] = num;
            if (solve(board, row, col + 1))
            {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int is_valid(int board[][BOARD_SIZE], int target, int r, int c)
{
    if (board == NULL)
    {
        printf("There is no board!");
        return 0;
    }
    // if there is already a target in the same row
    for (int row = 0; row < 9; ++row)
    {
        if (board[row][c] == target)
        {
            return 0;
        }
    }

    // if there is already a target in the same column
    for (int col = 0; col < 9; ++col)
    {
        if (board[r][col] == target)
        {
            return 0;
        }
    }
    int box_x = r / 3;
    int box_y = c / 3;
    // if there is already a target in the same 3x3 box
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[box_x*3 + row][box_y*3 + col] == target)
            {
                return 0;
            }
        }
    }
    return 1;
}

int finished(int board[][BOARD_SIZE])
{
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            if (board[row][col] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
