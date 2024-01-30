#include <stdio.h>
int main()
{
    int dim;
    scanf("%d", &dim);
    int target;
    scanf("%d", &target);
    int matrix[dim][dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // searching for the row
    int high = dim - 1;
    int low = 0;
    int row = 0;
    int mid;
    int found = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (target == matrix[mid][dim - 1])
        {
            printf("YES");
            found = 1;
            return 0;
        }
        else if (target < matrix[mid][dim - 1])
        {
            high = mid - 1;
            row = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    row++;
    // now we know the row we need to find the collumn in that row;
    high = dim - 1;
    low = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (target == matrix[row][mid])
        {
            printf("YES");
            found = 1;
            return 0;
        }
        else if (target < matrix[row][mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (!found)
    {
        printf("NO");
    }
    return 0;
}