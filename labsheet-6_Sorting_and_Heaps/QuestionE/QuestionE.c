#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high, int depth)
{
    if (depth == 0)
    {
        merge_sort(arr, low, high);
        return low;
    }

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void nomki_sort(int arr[], int low, int high, int depth)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, depth);

        // Recur on the left and right partitions
        nomki_sort(arr, low, pi - 1, depth - 1);
        nomki_sort(arr, pi + 1, high, depth - 1);
    }
}

void nomki_sort_wrapper(int arr[], int n)
{
    // Calculate the maximum depth for the given array size
    int max_depth = 2 * log2(n);

    // Initial call to nomki_sort with maximum depth
    nomki_sort(arr, 0, n - 1, max_depth);
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

    // Sort using Nomki sort
    nomki_sort_wrapper(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
