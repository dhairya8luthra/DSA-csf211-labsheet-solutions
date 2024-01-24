#include <stdio.h>

int main()
{
    int l, t;
    scanf("%d", &l);
    scanf("%d", &t);
    int arr[l];
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &arr[i]);
    }
    int high = l - 1;
    int low = 0;
    int mid;
    for (int i = 0; i < l; i++)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == t)
        {
            printf("%d", mid + 1);
            break;
        }
        else if (arr[mid] > t)
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