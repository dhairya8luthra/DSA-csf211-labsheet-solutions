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
    int right = 2 * i + 2;
    int left = 2 * i + 1;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
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
        swap(&arr[0], &arr[i]);
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