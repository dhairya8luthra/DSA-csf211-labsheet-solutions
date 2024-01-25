#include <stdio.h>

int main()
{
    int n;
    int matrix[n][n];
    scanf("%d", n);
    int top = 0;
    int bottom = n - 1;
    int right = n - 1;
    int left = 0;
    int num = 1;
    while (top <= bottom && left <= right)
    {
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
    }
}