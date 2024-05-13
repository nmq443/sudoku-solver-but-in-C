#include "board_generator.h"

int **init_board()
{
    int **board = (int**) malloc (BOARD_SIZE * sizeof(int*));
    if (board == NULL)
    {
        return NULL;
    }
    for (int row = 0; row < 9; ++row)
    {
        board[row] = (int*) malloc (sizeof(int));
        if (board[row] == NULL)
        {
            return NULL;
        }
    }

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            board[row][col] = 0;
        }
    }

    solve(&board, 0, 0);

    int attempts = (rand() % 30) + 17;

    while (attempts > 0)
    {
        int row = rand() % 9;
        int col = rand() % 9;

        while (board[row][col] == 0)
        {
            row = rand() % 9;
            col = rand() % 9;
        }

        board[row][col] = 0;
        --attempts;
    }
    print_board(board);
}
