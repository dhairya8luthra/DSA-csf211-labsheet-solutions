#include <stdio.h>
#include <stdbool.h>

bool isValid(int board[9][9], int row, int col, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;
        if (board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == -1)
            {
                for (int c = 1; c <= 9; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solve(board) == true)
                            return true;
                        else
                        {
                            board[i][j] = -1;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int board[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    printf("\n");

    solve(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}