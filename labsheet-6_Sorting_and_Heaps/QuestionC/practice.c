#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        Max_heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        Max_heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[i], &arr[0]);
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
}