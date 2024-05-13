#include "print.h"

//void print_board(int board[][BOARD_SIZE])
void print_board(int **board)
{
    for (int col = 0; col < BOARD_SIZE; ++col)
    {
        printf("+ - ");
    }
    printf("+\n");
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            if (!col)
            {
                printf("| ");
            }
            printf("%d | ", board[row][col]);
        }
        printf("\n");

        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            printf("+ - ");
            if (col == BOARD_SIZE - 1)
            {
                printf("+");
            }
        }       
        printf("\n");
    }
}
