#include <stdio.h>

int main()
{
    int len;
    int target;

    printf("Enter the length of array: ");
    scanf("%d", &len);
    printf("\nEnter the element to be searched in the array: ");
    scanf("%d", &target);
    // taking input
    int arr[len];
    printf("\nEnter %d integers for the array:\n", len);
    for (int i = 0; i < len; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int high = len - 1;
    int low = 0;
    int mid;
    int found = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            printf("\n%d is present at index %d.", target, mid + 1);
            found = 1;
            return 0;
        }
        if (arr[mid] > target)
        {
            high = mid - 1;
        }

        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
    }
    if (!found)
    {
        printf("Not found");
    }
    return 0;
}