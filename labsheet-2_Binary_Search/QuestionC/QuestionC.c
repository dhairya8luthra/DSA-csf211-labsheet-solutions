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
    int high = l - 1;
    int low = 0;
    int mid;
    int found = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[low] == arr[high] && arr[high] != 7)
        {
            break;
        }
        if (arr[mid] == 7)
        {
            printf("%d", mid);
            found = 1;
            break;
        }
        // chekcing the right side if it is sorted or not
        if (arr[mid] < arr[high])
        {
            // right side is sorted
            // search for 7
            if (arr[high] >= 7 && arr[mid] < 7)
            {
                // 7 is here reduce the search space
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else if (arr[mid] > arr[low])
        {
            // left side is sorted
            // search for seven
            if (arr[mid] > 7 && arr[low] <= 7)
            {
                // 7 is here
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    if (!found)
    {
        printf("-1");
    }
    return 0;
}