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
        if (arr[low] == arr[high] && arr[low] != 7)
        {
            break;
        }
        if (arr[mid] == 7)
        {
            printf("%d", mid);
            found = 1;
            return 0;
        }
        // check if the right side is sorted
        if (arr[high] > arr[mid])
        {
            // right side is sorted now check if 7 is here
            if (arr[mid] < 7 && arr[high] >= 7)
            {
                // 7 is heare bring the search space right
                low = mid + 1;
            }
            else
            {
                // 7 is not here search left side
                high = mid - 1;
            }
        }
        else if (arr[low] < arr[mid])
        {
            // 7 is on the left side check if 7 is here
            if (arr[mid] > 7 && arr[low] <= 7)
            {
                // 7 is here bring ssearch space to the left
                high = mid - 1;
            }
            else
            {
                // 7 is not here search in the right side
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