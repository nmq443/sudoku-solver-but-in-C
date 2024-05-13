#ifndef _SOLVER_H
#define _SOLVER_H 

#include <stdio.h>
#include <stdlib.h>
#include "print.h"

#define BOARD_SIZE 9

/*
int solve(int board[][BOARD_SIZE], int row, int col);

int is_valid(int board[][BOARD_SIZE], int target, int r, int c);

int finished(int board[9][9]);
*/

int solve(int ***board, int row, int col);

int is_valid(int ***board, int target, int r, int c);

int finished(int ***board);

#endif
