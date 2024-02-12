#include <stdio.h>

int main()
{
    int row, column;
    scanf("%d", &row);
    scanf("%d", &column);

    char board[row][column]; // Assuming the maximum column number is 10

    // Input board values
    for (int i = 0; i < row; i++)
    {
        scanf("%s", board[i]);
    }

    // Applying fall_column function to each column
    for (int i = 0; i < column; i++)
    {
        int last_obstacle_index = -1;

        // Find the last obstacle index
        for (int pointer = row - 1; pointer >= 0; pointer--)
        {
            if (board[pointer][i] == 'o')
            {
                last_obstacle_index = pointer;
                break;
            }
        }

        // Perform the falling process
        for (int pointer = row - 1; pointer >= 0; pointer--)
        {
            if (board[pointer][i] == '*')
            {
                // Move the coin downwards
                if (last_obstacle_index != -1 && pointer < last_obstacle_index - 1)
                {
                    board[last_obstacle_index - 1][i] = '*';
                    board[pointer][i] = '.';
                    last_obstacle_index--;
                }
            }
        }
    }

    // Print the updated board
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
