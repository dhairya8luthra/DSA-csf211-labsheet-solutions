#include <stdio.h>

int main()
{
    int n;
    printf("Please Enter the Number of Jerseys: ");
    scanf("%d", &n);

    // Increased the array size by 1 to include the nth element
    int arr[n];

    printf("\nPlease Enter the Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nPlease Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    int high = n - 1;
    int low = 0;
    int mid;

    while (low <= high)
    {

        mid = low + (high - low) / 2;

        if (arr[mid] == 7)
        {
            printf("\nThe Jersey with number 7 is at position %d.", mid);
            return 0;
        }

        // Check for the sorted side

        if (arr[mid] < arr[high])
        {
            // Right side is sorted
            if (arr[mid] < 7 && arr[high] >= 7)
            {
                // 7 is on the right side
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            // Left side is sorted
            if (arr[mid] > 7 && arr[low] <= 7)
            {
                // 7 is on the left side
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    printf("-1");

    return 0;
}
