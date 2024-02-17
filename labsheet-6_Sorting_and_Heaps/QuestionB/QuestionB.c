#include <stdio.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Qsort(int arr[], int high, int low)
{
    if (low < high)
    {
        int pivot = high;
        int pointer1 = low;
        int pointer2 = low;

        while (pointer1 < pivot)
        {
            if (arr[pointer1] < arr[pivot])
            {
                swap(arr, pointer1, pointer2);
                pointer1++;
                pointer2++;
            }
            else if (arr[pointer1] >= arr[pivot])
            {
                pointer1++;
            }
        }
        swap(arr, pivot, pointer2);

        // Recursively sort the sub-arrays
        Qsort(arr, pointer2 - 1, low);
        Qsort(arr, high, pointer2 + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int high = n - 1;
    int low = 0;

    Qsort(arr, high, low);

    // Printing the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
