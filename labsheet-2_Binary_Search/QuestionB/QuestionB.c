#include <stdio.h>

int main()
{
    // taking input
    int len;
    printf("Please Enter the Length of Array: ");
    scanf("%d", &len);
    printf("Please Enter the Array: ");
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        printf("\nEnter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    //
    int high = len - 1;
    int low = 0;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == len - 1 || arr[mid + 1] <= arr[mid]))
        {
            // arr[mid] is a peak element
            printf("Peak Element is at index %d and its value is %d\n", mid + 1, arr[mid]);
            break;
        }

        if (mid > 0 && arr[mid - 1] > arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return 0;
}
