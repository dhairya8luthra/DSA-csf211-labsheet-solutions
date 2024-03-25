#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in Quickselect
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quickselect algorithm
int quickselect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];

    int pivotIndex = partition(arr, low, high);
    int pivotRank = pivotIndex - low + 1;

    if (k == pivotRank)
        return arr[pivotIndex];
    else if (k < pivotRank)
        return quickselect(arr, low, pivotIndex - 1, k);
    else
        return quickselect(arr, pivotIndex + 1, high, k - pivotRank);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL)); // Seed the random number generator

    int kthLargest = quickselect(arr, 0, n - 1, n - k + 1);
    printf("%d\n", kthLargest);

    return 0;
}
