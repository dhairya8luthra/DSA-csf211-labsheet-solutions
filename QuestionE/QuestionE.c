#include <stdio.h>

int main()
{
    int dim;
    scanf("%d", &dim);

    int target;
    scanf("%d", &target);

    // Create a 2D array to store the numbers from 1 to dim
    int arr[dim][dim];

    // Input values into the 2D array
    int i, j;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++) // Fix: Change j <= dim to j < dim
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Binary search to find the row where target may exist
    int high = dim - 1;
    int low = 0;
    int mid, row = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid][0] <= target && target <= arr[mid][dim - 1]) // Fix: Change arr[mid][mid] to arr[mid][dim - 1]
        {
            // Target is in the current row
            row = mid;
            break;
        }
        else if (arr[mid][0] > target)
        {
            // Target is in the upper half
            high = mid - 1;
        }
        else
        {
            // Target is in the lower half
            low = mid + 1;
        }
    }

    if (row != -1)
    {
        // Binary search in the selected row to find the target column
        high = dim - 1; // Fix: Change high back to dim - 1
        low = 0;
        int col = -1;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (arr[row][mid] == target)
            {
                // Target found
                col = mid;
                break;
            }
            else if (arr[row][mid] > target)
            {
                // Target is in the left half
                high = mid - 1;
            }
            else
            {
                // Target is in the right half
                low = mid + 1;
            }
        }

        if (col != -1)
        {
            printf("Target found at row %d, column %d\n", row + 1, col + 1);
        }
        else
        {
            printf("Target not found\n");
        }
    }
    else
    {
        printf("Target not found\n");
    }

    return 0;
}
