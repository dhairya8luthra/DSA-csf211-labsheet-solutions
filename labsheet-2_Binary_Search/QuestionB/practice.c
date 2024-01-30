#include <stdio.h>

int main()
{
    int l;
    scanf("%d", &l);
    int arr[l];
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &arr[i]);
    }
    int high = l - 2;
    int low = 1;
    int mid;
    if (arr[0] > arr[1])
    {
        printf("%d", 1);
        return 0;
    }

    if (arr[l - 1] > arr[l - 2])
    {
        printf("%d", l);
        return 0;
    }
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid - 1] < arr[mid])
        {
            printf("%d", mid + 1);
            break;
        }
        if (arr[mid] < arr[mid - 1] && arr[mid + 1] < arr[mid])
        {
            high = mid - 1;
        }
        if (arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid])
        {
            low = mid + 1;
        }
    }
    return 0;
}