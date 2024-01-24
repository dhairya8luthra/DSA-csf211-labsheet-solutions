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
    int found = 0;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == 7)
        {
            printf("%d", mid);
            found = 1;
            return 0;
        }
        if (arr[low] == arr[high] && arr[low] != 7)
        {
            break;
        }
        if (arr[mid] < arr[high])
        {
            // right side is sorted
            // check for 7 is it there
            if (arr[mid] < 7 && arr[high] >= 7)
            {
                // 7 is here
                low = mid + 1;
            }
            else
            {
                // 7 is not here
                high = mid - 1;
            }
        }
        else if (arr[mid] > arr[low])
        {
            // left side is sorted
            // checking for 7
            if (arr[mid] > 7 && arr[low] <= 7)
            {
                // 7 is here
                high = mid - 1;
            }
            else
            {
                // 7 is not here
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