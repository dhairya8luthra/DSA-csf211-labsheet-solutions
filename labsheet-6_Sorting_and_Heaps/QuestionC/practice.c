#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Max_heapify(int arr[], int n, int i)
{
    // first find where the largest is
    // this init is what we want
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    // now i know the largest if it is not the ideal condition i will swap
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // now largest value is at i(root) and i will check all nodes below the low root value i have sent below
        Max_heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build the max heap O(n)
    // start from largest non leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Max_heapify(arr, n, i);
    }
    // now i will delete elements from the top of my heap and swap them to the end of my array
    // O(nlog(n))
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        // again build the max heap
        Max_heapify(arr, i, 0);
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
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}