#include <stdio.h>

// Swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in QuickSort
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

// Modified version of QuickSort to find kth smallest element
int select(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];

    int pivotIndex = partition(arr, low, high);
    int pivotRank = pivotIndex - low + 1;

    if (k == pivotRank)
        return arr[pivotIndex];
    else if (k < pivotRank)
        return select(arr, low, pivotIndex - 1, k);
    else
        return select(arr, pivotIndex + 1, high, k - pivotRank);
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
    +

        int kthLargest = select(arr, 0, n - 1, n - k + 1);
    printf("%d\n", kthLargest);

    return 0;
}
