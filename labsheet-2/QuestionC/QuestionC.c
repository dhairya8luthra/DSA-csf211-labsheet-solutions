#include <stdio.h>

int main()
{

    int n;
    printf("Please Enter the Number of Jerseys: ");
    scanf("%d", &n);
    printf("\nPlease Enter the Array: ");
    int arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        printf("\nPlease Enter the Element: ")
            scanf("%d", &arr[i]);
    }
    int high = arr[len - 1];
    int low = arr[0];
    int mid;

    while (low <= mid)
    {
        // Finding Mid element
        mid = low + (high - low) / 2;
        // check for the sorted size

        if (mid < high)
        {
            // right side is sorted
        }
    }

    return 0;
}