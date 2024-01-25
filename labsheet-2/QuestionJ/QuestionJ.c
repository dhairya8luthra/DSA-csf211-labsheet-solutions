#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int matrix[N][N];

    int top = 0, bottom = N - 1, left = 0, right = N - 1;
    int num = 1;

    while (top <= bottom && left <= right)
    {
        // Traverse from left to right (top row)
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = num++;
        }
        top++;

        // Traverse from top to bottom (right column)
        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = num++;
        }
        right--;

        // Traverse from right to left (bottom row)
        for (int i = right; i >= left; i--)
        {
            matrix[bottom][i] = num++;
        }
        bottom--;

        // Traverse from bottom to top (left column)
        for (int i = bottom; i >= top; i--)
        {
            matrix[i][left] = num++;
        }
        left++;
    }

    // Print the resulting matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
